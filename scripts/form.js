'use strict'


init();

    function init()
    {
        
            document.getElementById("subm_button").addEventListener('mousedown', handleMouseDownEvent);
            document.getElementById("subm_button").addEventListener('mouseup', handleMouseUpEvent);
            document.getElementById("subm_button").addEventListener("mouseleave", handleMouseUpEvent);
    }

    function handleMouseDownEvent(e)
    {
        let target = e.target;
        target.style.backgroundColor ="#282323";
    }
    function handleMouseUpEvent(e)
    {
        let target = e.target;
        target.style.backgroundColor ="#433b3b";
    }
   

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
    {
    closeFeedback();
    }
}

document.getElementById("feedback").onclick = function()
{
    document.getElementById("feedback_form_wrapper").style.animationName ="showFeedback";        /*activate fade effect*/
    document.getElementById("feedback_form_wrapper").style.display="block";
}

document.getElementById("form_close_button").onclick = closeFeedback;
 function closeFeedback()
{
    let f = [] ;
    f = f.concat(Array.prototype.slice.call(document.getElementsByTagName("input")));
    f = f.concat(Array.prototype.slice.call(document.getElementsByTagName("textarea")));
    
    let count = f.length;
    
    for(let i=0; i<count; i++)
    {
       
        f[i].classList.add("grey_placeholder");
        f[i].classList.remove("red_placeholder");
          
    }
    document.getElementById("feedback_form_wrapper").style.animationName = "hideFeedback";
    
    let st = window.getComputedStyle(document.getElementById("feedback_form_wrapper"),null);
    let dur = st.getPropertyValue("animation-duration");
    dur = Number.parseFloat(dur) * 1000;
   setTimeout(function(){
    document.getElementById("feedback_form").reset();
    document.getElementById("feedback_form_wrapper").style.display="none";
   }, dur );
    
}