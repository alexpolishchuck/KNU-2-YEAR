using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class finishScript : MonoBehaviour
{
    public static event System.Action PlayerHasFinsihedGame;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if (Collected.isSlotFull && other.transform.tag == "Player" && PlayerHasFinsihedGame != null)
        {
            
            PlayerHasFinsihedGame();

            Debug.Log(PlayerHasFinsihedGame);
        }
    }
    //private void OnTriggerStay(Collider other)
    //{
    //    if(Collected.isSlotFull && other.transform.tag == "Player")
    //    {
    //        Debug.Log("----------");
    //        PlayerHasFinsihedGame();
    //    }
    //}
}
