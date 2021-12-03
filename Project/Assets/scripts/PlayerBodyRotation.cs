using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerBodyRotation : MonoBehaviour
{

    [SerializeField]
    float MouseSensetivity;

    public Transform body;
    private float Xmouse;
    private float Ymouse;
    private float xRotation = 0f;

    void FixedUpdate()
    {
        Xmouse = Input.GetAxis("Mouse X")*MouseSensetivity;    
        body.Rotate(Vector3.up * Xmouse);    //vector3.up * Xmouse;
        Ymouse = Input.GetAxis("Mouse Y") * MouseSensetivity;

        xRotation -= Ymouse;
        xRotation = Mathf.Clamp(xRotation, -90f, 90f);
        transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f);
    }
}
