'use strict'

let selector = document.getElementById("selector");
let items = document.getElementsByClassName("item_wrapper");
let length = items.length;
let ind =0;
let numberofitems = 2

showItems();

selector.onclick = function(event)
{
    let selectorlength = selector.childElementCount;
    let selectorbuttons = selector.children;
    for(let i =0; i<selectorlength; i++)
    {
        if(selectorbuttons[i] === event.target){
            
            ind = i *numberofitems ;
            let itemholder = document.getElementById("item_holder");            
            showItems();
            itemholder.scrollIntoView({behavior:"smooth"});
            return;
        }
    }
    
}

function showItems(){
    for(let i = 0; i<length ; i++)
    {
        if(i < ind || i>= ind + numberofitems)
        items[i].style.display= "none";
        else if(i<ind + numberofitems)
        items[i].style.display= "block";
        

    }
    
    
    
}