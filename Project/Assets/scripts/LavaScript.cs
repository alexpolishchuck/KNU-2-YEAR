using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class LavaScript : MonoBehaviour
{
    [SerializeField]
    string objectTag;
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.tag == objectTag)
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
}
