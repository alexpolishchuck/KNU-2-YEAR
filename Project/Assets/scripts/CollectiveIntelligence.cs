using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollectiveIntelligence : MonoBehaviour
{
    public static bool IsPlayerSpotted = false;
    public static int pursuers = 0;

    private void Update()
    {
        if (pursuers == 0)
            IsPlayerSpotted = false;
        else
            IsPlayerSpotted = true;
    }



}
