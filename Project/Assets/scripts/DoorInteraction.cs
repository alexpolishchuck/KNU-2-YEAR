using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DoorInteraction : MonoBehaviour
{
    

    public float InteractionRange;
    Rigidbody rigb;

    private Vector3 OriginalRotation;

    bool isCRrunning = false;
    void Start()
    {
        rigb = GetComponent<Rigidbody>();
        OriginalRotation = transform.eulerAngles;
    }

    
    void Update()
    {
        
    }

    private void OnTriggerStay(Collider other)
    {
       
        if(other.tag == "Player" && Input.GetKeyDown(KeyCode.E) && !isCRrunning)
        {

            rigb.velocity = Vector3.zero;
            StartCoroutine(closetheDoor());
        }
        else if(other.tag=="Enemy")
        {
            rigb.AddForce(other.transform.forward * 0.5f, ForceMode.Impulse);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
       
        isCRrunning = false;
        StopAllCoroutines();
    }
    IEnumerator closetheDoor()
    {
      
        Vector3 rot = transform.eulerAngles;
        isCRrunning = true;
        Debug.Log(OriginalRotation.y);
        while (true)
        {
            
            if (Mathf.Abs(rot.y - OriginalRotation.y) < 0.05f)
            {
                rigb.velocity = Vector3.zero;
                break;
            }
            float rotAngle = Mathf.MoveTowardsAngle(transform.eulerAngles.y, OriginalRotation.y, 2.5f); //0.04f

            rot.y = rotAngle;
            
            transform.eulerAngles = rot;
            yield return null;
        }
        isCRrunning = false;
    }
}
