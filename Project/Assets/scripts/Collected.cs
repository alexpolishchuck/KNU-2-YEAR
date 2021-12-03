using System.Collections;
using System.Collections.Generic;
using UnityEngine;







public class Collected : MonoBehaviour
{
    public Rigidbody rigb;
    public BoxCollider coll;
    public GameObject instructions;
    public LayerMask ground;
    

    public Transform player, holder;

    public float pickUpRange;

    public static bool isSlotFull;
    private bool isequiped;
 

    void Start()
    {
        rigb = GetComponent<Rigidbody>();

        if(!isequiped)
        {
            rigb.isKinematic = false;
            coll.isTrigger = false;
        }

        
    }


    //void Update()
    //{
    //    Vector3 DistanceToPlayer = player.position - transform.position;
    //    if (!isequiped && DistanceToPlayer.magnitude <= pickUpRange && !isSlotFull)
    //    {
    //        instructions.SetActive(true);
    //        if (Input.GetKeyDown(KeyCode.E))
    //            pickup();
    //    }
    //    else
    //        instructions.SetActive(false);
    //}
    private void OnTriggerStay(Collider other)
    {
        if (!isequiped && other.tag =="Player" && !isSlotFull && !Physics.Linecast(other.transform.position,transform.position,ground))
        {
            Debug.Log(Physics.Linecast(other.transform.position, transform.position, ground));
            instructions.SetActive(true);
            if (Input.GetKeyDown(KeyCode.E))
                pickup();
        }
       
    }

    private void OnTriggerExit(Collider other)
    {
        instructions.SetActive(false);
    }

   

    void pickup()
    {
        isequiped = true;
        isSlotFull = true;

        rigb.isKinematic = true;
        coll.isTrigger = true;


        transform.SetParent(holder);
        transform.localPosition = Vector3.zero;
        transform.localRotation = Quaternion.Euler(0,0,90);


    }

    private void OnDestroy()                     //added 28.11
    {
        isSlotFull = false;
    }
}
