using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerHeadRotation : MonoBehaviour
{
    private void Start()
    {

        Cursor.lockState = CursorLockMode.Locked;
    }
    [SerializeField]
    float MouseSensetivity;

    private float Ymouse;
    private float xRotation = 0f;
    void FixedUpdate()
    {
        Ymouse = Input.GetAxis("Mouse Y") * MouseSensetivity;

        xRotation -= Ymouse;
        xRotation = Mathf.Clamp(xRotation, -70f, 15f);
        transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f);
        
        
    }
}
