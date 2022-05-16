'use strict'

let selector = document.getElementById("selector");
let items = document.getElementsByClassName("item_wrapper");
let length = items.length;
let ind =0;
let numberofitems = 2
let currentButtonId=0;


showItems();

selector.onclick = function(event)
{
    let selectorlength = selector.childElementCount;
    let selectorbuttons = selector.children;
    for(let i =0; i<selectorlength; i++)
    {
        if(selectorbuttons[i] === event.target){
            selectorbuttons[currentButtonId].style.backgroundColor = "";
            currentButtonId = i;
           
            ind = i *numberofitems ;
            let itemholder = document.getElementById("item_holder");            
            showItems();
            itemholder.scrollIntoView({behavior:"smooth"});
            return;
        }
    }
    
}

function showItems(){
    let selectorbuttons = selector.children;
    selectorbuttons[currentButtonId].style.backgroundColor = "#008B8B";

    for(let i = 0; i<length ; i++)
    {
        if(i < ind || i>= ind + numberofitems)
        items[i].style.display= "none";
        else if(i<ind + numberofitems)
        items[i].style.display= "block";
        

    }
    
    
    
}