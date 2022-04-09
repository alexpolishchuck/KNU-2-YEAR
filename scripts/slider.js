'use strict'

let slideIndex =0;
let prevIndex= 0;
let nextIndex = 0;
let Timer; 
let slides = document.getElementsByClassName("slider_image");
let radio_buttons = document.getElementsByClassName("custom_radio");
let radio_buttonsHolder = document.getElementById("slider_selector");
let leftbutton = document.getElementById("left_button");
let rightbutton = document.getElementById("right_button");
let len = slides.length;

initialSlide();

function activateSlide()
{
        slides[slideIndex].classList.remove("inactive_img")
        slides[slideIndex].classList.add("active_img");
        radio_buttons[slideIndex].classList.remove("inactive_radio") ;
        radio_buttons[slideIndex].classList.add("active_radio") ;
}
function deactivateSlide()
{
        slides[slideIndex].classList.remove("active_img")
        slides[slideIndex].classList.add("inactive_img");
        radio_buttons[slideIndex].classList.remove("active_radio") ;
        radio_buttons[slideIndex].classList.add("inactive_radio") ;
}

function nextslide()
{
    clearTimeout(Timer);
    deactivateSlide();
    slideIndex++;
    if(slideIndex == len)
    slideIndex = 0;
    activateSlide();
    Timer = setTimeout(nextslide,4000);
}

function prevslide()
{
    clearTimeout(Timer);
    deactivateSlide();
    slideIndex--;
    if(slideIndex < 0)
    slideIndex = len-1;
    activateSlide();
    Timer = setTimeout(nextslide,4000);
}

rightbutton.onclick = function rightbuttonClicked()
{
    nextslide();
}

leftbutton.onclick = function leftbuttonClicked()
{
    prevslide();
}

function radbutholderClicked(ev)
{
   
    
    for(let i =0; i<len; i++)
    {
        if(radio_buttons[i] === ev.target){
            clearTimeout(Timer);
            deactivateSlide();
        slideIndex = i;
        activateSlide();
        
        }
    }
  
   
    
}

function initialSlide()
{
       
        for(slideIndex=0; slideIndex<len; slideIndex++)
        {
            deactivateSlide();
            
        }
        slideIndex =0;
        activateSlide();
        radio_buttonsHolder.addEventListener('click', radbutholderClicked);
        Timer = setTimeout(nextslide,4000);

        
}

