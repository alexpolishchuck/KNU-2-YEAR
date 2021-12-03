using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControls : MonoBehaviour
{




    [SerializeField]
    public float speed;
    [SerializeField]
    public float trst;

    [SerializeField]
    public float noiseradiuse = 6.0f;
    [SerializeField]
    GameObject UpperRay;
    [SerializeField]
    GameObject LowerRay;
    [SerializeField]
    float smoothstep = 0.5f;
    [SerializeField]
    float LowerLength;
    [SerializeField]
    float UpperLength;
    
   

    public Transform GroundCheck;
    public Transform body;

    [SerializeField]
    private bool isgrounded;
    private bool isdisabled;
    public float SphereRadius;
  

   public LayerMask GroundMask;
    public LayerMask ObstacleMask;

    private Rigidbody rigb;

    float StopSlidingParameter = 1f;
    private float CurrentGravity = -19.62f;

    private void Start()
    {
        rigb = GetComponent<Rigidbody>();

        EnemyBehaviour.GuardHasCollidedWithPlayer += disable;
        finishScript.PlayerHasFinsihedGame += disable;
      
    }
    void Update()
    {

        // Input values
        
            float x = Input.GetAxisRaw("Horizontal");
            float z = Input.GetAxisRaw("Vertical");
        
        Vector3 move = new Vector3(0f, 0f, 0f);


        //jumping
         isgrounded = Physics.CheckSphere(GroundCheck.position, SphereRadius, GroundMask);  //turn it on
        if(!isgrounded)
            isgrounded = Physics.CheckSphere(GroundCheck.position, SphereRadius, ObstacleMask);


        if (isgrounded)
        {
            if (move.y < 0)
                move.y = -2f;

            if (x != 0 || z != 0)
            {
     

                stepup();
            }
            
        }
        else
            move.y -= 0.5f;

        if (Input.GetButtonDown("Jump") && isgrounded && !isdisabled)    //& move.y==0? delete !isdisabled
        {
            move.y = Mathf.Sqrt(2f * (-2) * CurrentGravity);
         
        }
        //GetComponent<Rigidbody>().velocity += move;
        
        if(Input.GetKeyDown(KeyCode.LeftShift))                //increase speed + noise
        {
            speed += 5;
            noiseradiuse += 5f;
        }
        else if(Input.GetKeyUp(KeyCode.LeftShift))
        {
            speed -= 5;
            noiseradiuse -= 5f;
        }

        if (Input.GetKeyDown(KeyCode.LeftControl))             //decrease speed and noise
        {
            speed -= 3f;
            noiseradiuse -= 3f;
        }
        else if (Input.GetKeyUp(KeyCode.LeftControl))
        {
            speed += 3f;
            noiseradiuse += 3f;
        }




        if (!isdisabled)                            //if player wasn't disabled by guard     //delete
            move += (transform.right * x + transform.forward * z) * speed * Time.deltaTime;

        Vector2 mag = findrelativevelocity();

        if (Mathf.Abs(mag.x) > 0.01 && Mathf.Abs(x) < 0.05f /*|| (mag.x < -0.01 && x > 0) || (mag.x > 0.01 && x < 0)*/)
        {
           move +=(speed * transform.right * Time.deltaTime * -mag.x * StopSlidingParameter);
        }
        if (Mathf.Abs(mag.y) > 0.01 && Mathf.Abs(z) < 0.05f /*|| (mag.y < -0.01 && z > 0) || (mag.y > 0.01 && z < 0)*/)
        {
           move+=(speed *transform.forward * Time.deltaTime * -mag.y * StopSlidingParameter);
        }

       

        GetComponent<Rigidbody>().velocity += move;

        if (Mathf.Sqrt(Mathf.Pow(GetComponent<Rigidbody>().velocity.x, 2) + Mathf.Pow(GetComponent<Rigidbody>().velocity.z, 2)) > speed)
        {

            float Y = GetComponent<Rigidbody>().velocity.y;
            Vector3 a = GetComponent<Rigidbody>().velocity.normalized * speed;
            a.y = Y;
            GetComponent<Rigidbody>().velocity = a;
        }


        
    }


    private void disable()           //delete
    {
        isdisabled = true;
     
    }

    private void OnDestroy()
    {
        EnemyBehaviour.GuardHasCollidedWithPlayer -= disable;
        finishScript.PlayerHasFinsihedGame -= disable;
    }

    private Vector2 findrelativevelocity()
    {
        Vector2 relvel = new Vector2() ;
        float lookAngle = body.transform.eulerAngles.y;
        float moveAngle = Mathf.Atan2(rigb.velocity.x, rigb.velocity.z) * Mathf.Rad2Deg;

        float u = Mathf.DeltaAngle(lookAngle, moveAngle);
       
        float mag = rigb.velocity.magnitude;
        float zMag = mag * Mathf.Cos(u * Mathf.Deg2Rad);
        float xMag = mag * Mathf.Cos((90 - u) * Mathf.Deg2Rad);
        relvel.x = xMag;
        relvel.y = zMag;
        return relvel;
    }

    private void stepup()
    {

        RaycastHit LowerHit;
        if (Physics.Raycast(LowerRay.transform.position, LowerRay.transform.forward, out LowerHit, LowerLength))
        {
        
            RaycastHit UpperHit;
            if (!Physics.Raycast(UpperRay.transform.position, UpperRay.transform.forward, out UpperHit, UpperLength))
            {

                //rigb.position += new Vector3(0, smoothstep, 0);
                //transform.position += new Vector3(0, smoothstep, 0);    //or this one 
               // transform.position += transform.forward * 0.2f;         //or this one
                  Vector3 targetposition = transform.position;       // this one
                  targetposition.y += smoothstep;                   //this one
                 transform.position =  Vector3.Lerp(transform.position, targetposition, Time.deltaTime*4); //this one 
                //Vector3 thrust = rigb.velocity.normalized;
                // thrust.y = 0;
                //rigb.AddForce(thrust*trst,ForceMode.Impulse);
                 rigb.AddForce(LowerRay.transform.forward * trst, ForceMode.Impulse);  //this one
            }
        }
    }
    //rigb.velocity
    private void OnDrawGizmos()
    {
        Gizmos.DrawRay(LowerRay.transform.position, LowerRay.transform.forward * LowerLength);
        Gizmos.color = Color.black;
        Gizmos.DrawRay(UpperRay.transform.position, UpperRay.transform.forward * UpperLength);
        // Gizmos.DrawSphere(StepCheck.position, Spherecast);
        Gizmos.DrawSphere(GroundCheck.position, SphereRadius);
        
    }

}
