using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOver : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject PlayerWonUI;
    public GameObject PlayerLostUI;
   // public Transform canvas;

   private bool gameislost =false;
    private bool gameiswon = false;

    void Start()
    {
        EnemyBehaviour.GuardHasCollidedWithPlayer += showLoseMesssage;
        finishScript.PlayerHasFinsihedGame += showWinMessage;
       
    }

    // Update is called once per frame
    void Update()
    {
        if(gameislost && Input.GetKeyDown(KeyCode.Space))
        {
            SceneManager.LoadScene(0);
        }
        else
        if (gameiswon && Input.GetKeyDown(KeyCode.Space))
        {
            Cursor.lockState = CursorLockMode.None;
            SceneManager.LoadScene("Menu");
        }
    }

    void showWinMessage()
    {
        //foreach(GameObject child in transform  )
        //{
        //    child.SetActive(false);
        //}
        if (!gameislost)
        {
            if (PlayerWonUI != null)
                PlayerWonUI.SetActive(true);
            gameiswon = true;
            
        }
        finishScript.PlayerHasFinsihedGame -= showWinMessage;
    }

    void showLoseMesssage()
    {
        //foreach (GameObject child in transform)
        //{
        //    child.SetActive(false);


        //}
        if (!gameiswon)
        {
            if (PlayerLostUI != null)
                PlayerLostUI.SetActive(true);
            gameislost = true;
            
        }
        EnemyBehaviour.GuardHasCollidedWithPlayer -= showLoseMesssage;
    }
}
