'use strict'


let currentid=0;
let itemcounter=5;
let selector = document.getElementById("selector");

showrows();


selector.onclick = function(event)
{
    let selectorlength = selector.childElementCount;
    let selectorbuttons = selector.children;
    for(let i =0; i<selectorlength; i++)
    {
        if(selectorbuttons[i] === event.target){
            selectorbuttons[currentid].style.backgroundColor = "";
            hiderows();
            currentid = i;
            showrows();
            return;
        }
    }
    
}

function hiderows()
{
    let tbl = document.getElementsByClassName("custom_table");
    tbl = Array.prototype.slice.call(tbl)[0];
    let children= tbl.rows;
    children = Array.prototype.slice.call(children);
    let size = children.length;
    for(let i=1 + currentid*itemcounter; i< 1 + (currentid + 1)*itemcounter && i<size; i++)
    {
        children[i].style.display= "none";
    }
}
function showrows()
{
    let selectorbuttons = selector.children;
    selectorbuttons[currentid].style.backgroundColor = "#008B8B";
    let tbl = document.getElementsByClassName("custom_table");
    tbl = Array.prototype.slice.call(tbl)[0];
    let children= tbl.rows;
    children = Array.prototype.slice.call(children);
    children[0].style.display= "table-row";
    let size = children.length;
    for(let i=1 + currentid*itemcounter; i< 1+ (currentid + 1)*itemcounter && i<size; i++)
    { 
        children[i].style.display= "table-row";
    }

}