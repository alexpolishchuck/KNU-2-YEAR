'use strict'

function ValidateEmail(input) {

    var validRegex = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
  
    if (input.match(validRegex)) {
  
      return true;
  
    } else {
  
      alert("Invalid email address!");
  
      return false;
  
    }
}
document.getElementById("subm_button").onclick = function()
{
    
    let f = [] ;
    f = f.concat(Array.prototype.slice.call(document.getElementsByTagName("input")));
    f = f.concat(Array.prototype.slice.call(document.getElementsByTagName("textarea")));
    
    let count = f.length;
    let is_invalid = false;
    for(let i=0; i<count; i++)
    {
        if(f[i].value == ""){
            is_invalid = true;
        f[i].classList.remove("grey_placeholder");
        f[i].classList.add("red_placeholder");
            break;
        }
    }
    
    if(!is_invalid && ValidateEmail(document.getElementById("e-mail").value))
    document.querySelector("form").reset();
}