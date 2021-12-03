using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;


public class EnemyBehaviour : MonoBehaviour
{
    public static event System.Action GuardHasCollidedWithPlayer;

    //check
    public Vector3 vel;                //delete
    [SerializeField]
    private bool isSearchRunning = false;
    [SerializeField]
    private int ishit = 0;

    public Transform Path;
    public Transform GroundCheck;

    //player configurations
    private Transform Player;
    private bool isPlayerSpotted;
    [SerializeField]
    private Vector3 lastSpottedPos;
    private Vector3 movementdir;


    //enemy's characteristics 
    public NavMeshAgent agent;
    public float rotspeed;
    public float ViewDistance = 12.27f;
    private float defaultVD = 12.27f;
    private float spotdistance = 3f;
    private float CollectiveSpottingDistance = 6f;      //added collective
    private float Viewangle;
    private bool checkedLastPlayerPos = true;
    [SerializeField]
    private float timer = 0.5f;
    private float defaultT = 0.5f;
    private float hittingdistance = 1.35f;          //check
    private float speed;
    private float increasedspeed;


    [SerializeField]
    private float turnaroundangle = 180f;

    //waypoints
    private Vector3[] waypoints;
    private int index = 0;
   


    //light
    public Light spotlight;
    //masks
    public LayerMask GroundMask;
    public LayerMask Obstacle;


    private bool isgrounded;
   
    private void Start()
    {
        Viewangle = spotlight.spotAngle;
        waypoints = new Vector3[Path.childCount];
        Player = GameObject.FindGameObjectWithTag("Player").transform;
        for (int i = 0; i < Path.childCount; i++)
        {
            waypoints[i] = Path.GetChild(i).position;

        }

        speed = agent.speed;
        increasedspeed = speed + 10f;                                 //delete
        

    }
    private void Update()
    {
        


       
        if (GetComponent<Rigidbody>().velocity.magnitude > 0.05f)
        {
            GetComponent<Rigidbody>().velocity *= 0;
        }


        canSeePlayer(); //checking if enemy can see the player
        CanHearPlayer();           //checking if enemy can hear the player

        //if (CollectiveIntelligence.pursuers != 0 && Vector3.Distance(transform.position, Player.position)<=CollectiveSpottingDistance && !isPlayerSpotted)
        //{
        //    isPlayerSpotted = true;
        //    CollectiveIntelligence.pursuers += 1;
        //}


        if (!isPlayerSpotted)
        {
            ViewDistance = defaultVD;

           

            PlayerIsntSpotted();
           
        }
        else
        if (isPlayerSpotted)  //if player is spotted
        {
            ViewDistance = defaultVD + 1f;
           

            StopAllCoroutines();                    //EXTREMELY PERILOUS


            timer = defaultT;               //resetting timer, not activated
            turnaroundangle = 180f;         //resetting angle of rotation

            agent.angularSpeed = 150;

            spotlight.color = Color.red;
            agent.isStopped = false;
            isSearchRunning = false;         //added recently
            transform.LookAt(Player);
            agent.SetDestination(Player.position);

        }
        
    }



  //  checking collision with player
   void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Player" && GuardHasCollidedWithPlayer != null)
        {
            Rigidbody rb = collision.gameObject.GetComponent<Rigidbody>();
            rb.constraints = RigidbodyConstraints.None;
            rb.AddForce(transform.forward * 20, ForceMode.Impulse);
            GuardHasCollidedWithPlayer();
        }
    }
    private void canSeePlayer()
    {
       


        Vector3 dirToPlayer = Player.position - transform.position;
        float angle = Vector3.Angle(transform.forward, dirToPlayer);
       
        if (Vector3.Distance(transform.position, Player.position) < ViewDistance && angle < Viewangle / 2f && !Physics.Linecast(transform.position, Player.position, Obstacle)) // || hit info
        {
            

            lastSpottedPos = Player.position;
            isSearchRunning = false;            // player is found

            checkedLastPlayerPos = false;
            isPlayerSpotted = true;
        }
        else
            isPlayerSpotted = false;


    }

    void CanHearPlayer()
    {
        if(Vector3.Distance(transform.position, Player.position) <= spotdistance)
        {
            lastSpottedPos = Player.position;
            isSearchRunning = false;            // player is found

            checkedLastPlayerPos = false;
            isPlayerSpotted = true;
        }
        else
        if (Vector3.Distance(transform.position, Player.position) <= Player.GetComponent<PlayerControls>().noiseradiuse)
        {
            lastSpottedPos = Player.position;

            agent.isStopped = false;                //added recently

            checkedLastPlayerPos = false;
          //  StopAllCoroutines();                    //EXTREMELY PERILOUS
        }

    }

    void PlayerIsntSpotted()
    {
        if (checkedLastPlayerPos)
        {

            patrol();
            spotlight.color = Color.white;

        }
        else
        {
            spotlight.color = Color.yellow;

            agent.SetDestination(lastSpottedPos);
            Vector3 Distance = GroundCheck.position - lastSpottedPos;

            RaycastHit hit;                                                     //added recently
            Physics.Raycast(transform.position, transform.forward, out hit);
            if (isSearchRunning && hit.distance <= hittingdistance && hit.rigidbody == null)
            {
                isSearchRunning = false;
                StartCoroutine(TurnAround());
            }
            
            if(!checkedLastPlayerPos)
            if ((Distance.magnitude < 0.5f || timer < 0.05f) && agent.isStopped == false)
            {
                agent.velocity *= 0;

                    checkedLastPlayerPos = true;
                    timer = defaultT;

                    if (!isSearchRunning)
                        search();                  //searching for player
                    else
                    {
                        isSearchRunning = false;
                        patrol();                  //patrolling again
                    }
                

            }
            else
            if (agent.velocity.magnitude < 0.5)         //enemy stopped
                timer -= Time.deltaTime;
            else
                timer = defaultT;                          //reseting timer, not activated
        }
    }

    private void patrol()
    {
        agent.SetDestination(waypoints[index]);
       


        Vector3 Distance = GroundCheck.position - waypoints[index];
        if (Distance.magnitude < 0.8f)
        {
            agent.angularSpeed = rotspeed;

            agent.velocity *= 0;
            index = (index + 1) % Path.childCount;
            agent.isStopped = true;



            StartCoroutine(LookAtTarget());
        


        }
        else if(agent.isStopped ==false)               //added
        {
           
            agent.angularSpeed = 150;

        }
    }

    private void search()
    {
        isSearchRunning = true;
        checkedLastPlayerPos = false;

        float newx = Random.Range(-15, 15);
        float newz = Random.Range(-15,15);
       
        lastSpottedPos = Player.position + transform.right*newx + transform.forward*newz;
        agent.SetDestination(lastSpottedPos);
        


        //timer -= Time.deltaTime;
        //if (timer < 0.05f)
        //{
        //    isSearchRunning = false;
        //    timer = 3f;
        //    agent.speed = 5f;
        //}
        //else
        //{
        //    isSearchRunning = true;
        //    agent.speed = 3f;

        //    if (searchpointset == false)
        //    {
        //        int multiplier = Random.Range(1, 10);
        //        searchpoint = lastSpottedPos + multiplier * movementdir;
        //        agent.SetDestination(searchpoint);
        //        searchpointset = true;


        //    }

        //    Vector3 dist = searchpoint - transform.position;
        //    if (dist.magnitude < 0.05f)
        //    {
        //        isSearchRunning = false;
        //        timer = 3f;
        //        agent.speed = 5f;
        //    }


        //}

    }



    IEnumerator LookAtTarget()
    {
     
        Vector3 DirToLook = (waypoints[index] - GroundCheck.position).normalized;
        float Angle = 90 - Mathf.Atan2(DirToLook.z, DirToLook.x) * Mathf.Rad2Deg;

        
        while (true)
        {
          
            if (Mathf.Abs(Mathf.DeltaAngle(transform.eulerAngles.y, Angle)) < 0.05f)
            {
                agent.isStopped = false;
                
                break;
            }
            float rotAngle = Mathf.MoveTowardsAngle(transform.eulerAngles.y, Angle, rotspeed * 0.05f);//rotspeed
            transform.eulerAngles = Vector3.up * rotAngle;
            yield return null;
        }



    }

    IEnumerator TurnAround()
    {
        agent.isStopped = true;
        RaycastHit hit;
        if (Physics.Raycast(transform.position, transform.forward, out hit))
            ishit++; 
        while (hit.distance <= hittingdistance)
        {
            float angle = rotspeed * 0.025f;
            //  turnaroundangle -= rotspeed * 0.05f;
            //transform.localRotation = Quaternion.Euler(0, angle, 0);
            transform.eulerAngles += Vector3.up * angle;
           // angle = Mathf.MoveTowardsAngle(transform.eulerAngles.y, (transform.eulerAngles.y + angle)%360f, rotspeed * 0.025f);//rotspeed
            //transform.eulerAngles = Vector3.up * angle;
            if (!Physics.Raycast(transform.position, transform.forward, out hit))
                break;
                yield return null;
        }

        // agent.SetDestination(transform.position);           //check
        agent.ResetPath();                                    //delete
        ishit = -1;
            agent.isStopped = false;
        checkedLastPlayerPos = true;                          //delete
        timer = defaultT;                                     //delete
    }

    private void OnDrawGizmos()
    {
        Vector3 previous = Path.GetChild(0).position;
        

        foreach(Transform waypoint in Path)
        {
            Gizmos.color = Color.black;
            if (waypoint!= Path.GetChild(0))
            {
          
                Gizmos.DrawLine(previous, waypoint.position);
                previous = waypoint.position;
            }
            Gizmos.DrawSphere(waypoint.position, 0.3f);
            
        }
        Gizmos.DrawLine(previous, Path.GetChild(0).position);
        Gizmos.DrawSphere(GroundCheck.position, 0.8f);
        Gizmos.color = Color.black;
        //Gizmos.DrawRay(transform.position, transform.forward*ViewDistance);
        Gizmos.DrawRay(transform.position, transform.forward * hittingdistance);


    }
   
}





//void PlayerIsntSpotted()
//{
//    if (checkedLastPlayerPos)
//    {

//        patrol();
//        spotlight.color = Color.white;

//    }
//    else
//    {
//        spotlight.color = Color.yellow;

//        agent.SetDestination(lastSpottedPos);
//        Vector3 Distance = GroundCheck.position - lastSpottedPos;

//        if (Distance.magnitude < 0.5f || timer < 0.05f)
//        {
//            agent.velocity *= 0;

//            RaycastHit hit;
//            Physics.Raycast(transform.position, transform.forward, out hit);
//            if (hit.distance <= hittingdistance && hit.rigidbody == null)
//                StartCoroutine(TurnAround());
//            else
//            {
//                checkedLastPlayerPos = true;
//                timer = defaultT;

//                if (!isSearchRunning)
//                    search();                  //searching for player
//                else
//                {
//                    isSearchRunning = false;
//                    patrol();                  //patrolling again
//                }
//            }

//        }
//        else
//        if (agent.velocity.magnitude < 0.5)         //enemy stopped
//            timer -= Time.deltaTime;
//        else
//            timer = defaultT;                          //reseting timer, not activated
//    }
//}