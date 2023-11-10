const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
  <title>AVE RnD : CW Keyer 1.20</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  
  
    
<style>
/* W3.CSS 4.15 December 2020 by Jan Egil and Borge Refsnes */
html{box-sizing:border-box}*,*:before,*:after{box-sizing:inherit}
/* Extract from normalize.css by Nicolas Gallagher and Jonathan Neal git.io/normalize */
html{-ms-text-size-adjust:100%;-webkit-text-size-adjust:100%}body{margin:0}
article,aside,details,figcaption,figure,footer,header,main,menu,nav,section{display:block}summary{display:list-item}
audio,canvas,progress,video{display:inline-block}progress{vertical-align:baseline}
audio:not([controls]){display:none;height:0}[hidden],template{display:none}
a{background-color:transparent}a:active,a:hover{outline-width:0}
abbr[title]{border-bottom:none;text-decoration:underline;text-decoration:underline dotted}
b,strong{font-weight:bolder}dfn{font-style:italic}mark{background:#ff0;color:#000}
small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}
sub{bottom:-0.25em}sup{top:-0.5em}figure{margin:1em 40px}img{border-style:none}
code,kbd,pre,samp{font-family:monospace,monospace;font-size:1em}hr{box-sizing:content-box;height:0;overflow:visible}
button,input,select,textarea,optgroup{font:inherit;margin:0}optgroup{font-weight:bold}
button,input{overflow:visible}button,select{text-transform:none}
button,[type=button],[type=reset],[type=submit]{-webkit-appearance:button}
button::-moz-focus-inner,[type=button]::-moz-focus-inner,[type=reset]::-moz-focus-inner,[type=submit]::-moz-focus-inner{border-style:none;padding:0}
button:-moz-focusring,[type=button]:-moz-focusring,[type=reset]:-moz-focusring,[type=submit]:-moz-focusring{outline:1px dotted ButtonText}
fieldset{border:1px solid #c0c0c0;margin:0 2px;padding:.35em .625em .75em}
legend{color:inherit;display:table;max-width:100%;padding:0;white-space:normal}textarea{overflow:auto}
[type=checkbox],[type=radio]{padding:0}
[type=number]::-webkit-inner-spin-button,[type=number]::-webkit-outer-spin-button{height:auto}
[type=search]{-webkit-appearance:textfield;outline-offset:-2px}
[type=search]::-webkit-search-decoration{-webkit-appearance:none}
::-webkit-file-upload-button{-webkit-appearance:button;font:inherit}
/* End extract */
html,body{font-family:Verdana,sans-serif;font-size:15px;line-height:1.5}html{overflow-x:hidden}
h1{font-size:36px}h2{font-size:30px}h3{font-size:24px}h4{font-size:20px}h5{font-size:18px}h6{font-size:16px}
.w3-serif{font-family:serif}.w3-sans-serif{font-family:sans-serif}.w3-cursive{font-family:cursive}.w3-monospace{font-family:monospace}
h1,h2,h3,h4,h5,h6{font-family:"Segoe UI",Arial,sans-serif;font-weight:400;margin:10px 0}.w3-wide{letter-spacing:4px}
hr{border:0;border-top:1px solid #eee;margin:20px 0}
.w3-image{max-width:100%;height:auto}img{vertical-align:middle}a{color:inherit}
.w3-table,.w3-table-all{border-collapse:collapse;border-spacing:0;width:100%;display:table}.w3-table-all{border:1px solid #ccc}
.w3-bordered tr,.w3-table-all tr{border-bottom:1px solid #ddd}.w3-striped tbody tr:nth-child(even){background-color:#f1f1f1}
.w3-table-all tr:nth-child(odd){background-color:#fff}.w3-table-all tr:nth-child(even){background-color:#f1f1f1}
.w3-hoverable tbody tr:hover,.w3-ul.w3-hoverable li:hover{background-color:#ccc}.w3-centered tr th,.w3-centered tr td{text-align:center}
.w3-table td,.w3-table th,.w3-table-all td,.w3-table-all th{padding:8px 8px;display:table-cell;text-align:left;vertical-align:top}
.w3-table th:first-child,.w3-table td:first-child,.w3-table-all th:first-child,.w3-table-all td:first-child{padding-left:16px}
.w3-btn,.w3-button{border:none;display:inline-block;padding:8px 16px;vertical-align:middle;overflow:hidden;text-decoration:none;color:inherit;background-color:inherit;text-align:center;cursor:pointer;white-space:nowrap}
.w3-btn:hover{box-shadow:0 8px 16px 0 rgba(0,0,0,0.2),0 6px 20px 0 rgba(0,0,0,0.19)}
.w3-btn,.w3-button{-webkit-touch-callout:none;-webkit-user-select:none;-khtml-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}   
.w3-disabled,.w3-btn:disabled,.w3-button:disabled{cursor:not-allowed;opacity:0.3}.w3-disabled *,:disabled *{pointer-events:none}
.w3-btn.w3-disabled:hover,.w3-btn:disabled:hover{box-shadow:none}
.w3-badge,.w3-tag{background-color:#000;color:#fff;display:inline-block;padding-left:8px;padding-right:8px;text-align:center}.w3-badge{border-radius:50%}
.w3-ul{list-style-type:none;padding:0;margin:0}.w3-ul li{padding:8px 16px;border-bottom:1px solid #ddd}.w3-ul li:last-child{border-bottom:none}
.w3-tooltip,.w3-display-container{position:relative}.w3-tooltip .w3-text{display:none}.w3-tooltip:hover .w3-text{display:inline-block}
.w3-ripple:active{opacity:0.5}.w3-ripple{transition:opacity 0s}
.w3-input{padding:8px;display:block;border:none;border-bottom:1px solid #ccc;width:100%}
.w3-select{padding:9px 0;width:100%;border:none;border-bottom:1px solid #ccc}
.w3-dropdown-click,.w3-dropdown-hover{position:relative;display:inline-block;cursor:pointer}
.w3-dropdown-hover:hover .w3-dropdown-content{display:block}
.w3-dropdown-hover:first-child,.w3-dropdown-click:hover{background-color:#ccc;color:#000}
.w3-dropdown-hover:hover > .w3-button:first-child,.w3-dropdown-click:hover > .w3-button:first-child{background-color:#ccc;color:#000}
.w3-dropdown-content{cursor:auto;color:#000;background-color:#fff;display:none;position:absolute;min-width:160px;margin:0;padding:0;z-index:1}
.w3-check,.w3-radio{width:24px;height:24px;position:relative;top:6px}
.w3-sidebar{height:100%;width:200px;background-color:#fff;position:fixed!important;z-index:1;overflow:auto}
.w3-bar-block .w3-dropdown-hover,.w3-bar-block .w3-dropdown-click{width:100%}
.w3-bar-block .w3-dropdown-hover .w3-dropdown-content,.w3-bar-block .w3-dropdown-click .w3-dropdown-content{min-width:100%}
.w3-bar-block .w3-dropdown-hover .w3-button,.w3-bar-block .w3-dropdown-click .w3-button{width:100%;text-align:left;padding:8px 16px}
.w3-main,#main{transition:margin-left .4s}
.w3-modal{z-index:3;display:none;padding-top:100px;position:fixed;left:0;top:0;width:100%;height:100%;overflow:auto;background-color:rgb(0,0,0);background-color:rgba(0,0,0,0.4)}
.w3-modal-content{margin:auto;background-color:#fff;position:relative;padding:0;outline:0;width:600px}
.w3-bar{width:100%;overflow:hidden}.w3-center .w3-bar{display:inline-block;width:auto}
.w3-bar .w3-bar-item{padding:8px 16px;float:left;width:auto;border:none;display:block;outline:0}
.w3-bar .w3-dropdown-hover,.w3-bar .w3-dropdown-click{position:static;float:left}
.w3-bar .w3-button{white-space:normal}
.w3-bar-block .w3-bar-item{width:100%;display:block;padding:8px 16px;text-align:left;border:none;white-space:normal;float:none;outline:0}
.w3-bar-block.w3-center .w3-bar-item{text-align:center}.w3-block{display:block;width:100%}
.w3-responsive{display:block;overflow-x:auto}
.w3-container:after,.w3-container:before,.w3-panel:after,.w3-panel:before,.w3-row:after,.w3-row:before,.w3-row-padding:after,.w3-row-padding:before,
.w3-cell-row:before,.w3-cell-row:after,.w3-clear:after,.w3-clear:before,.w3-bar:before,.w3-bar:after{content:"";display:table;clear:both}
.w3-col,.w3-half,.w3-third,.w3-twothird,.w3-threequarter,.w3-quarter{float:left;width:100%}
.w3-col.s1{width:8.33333%}.w3-col.s2{width:16.66666%}.w3-col.s3{width:24.99999%}.w3-col.s4{width:33.33333%}
.w3-col.s5{width:41.66666%}.w3-col.s6{width:49.99999%}.w3-col.s7{width:58.33333%}.w3-col.s8{width:66.66666%}
.w3-col.s9{width:74.99999%}.w3-col.s10{width:83.33333%}.w3-col.s11{width:91.66666%}.w3-col.s12{width:99.99999%}
@media (min-width:601px){.w3-col.m1{width:8.33333%}.w3-col.m2{width:16.66666%}.w3-col.m3,.w3-quarter{width:24.99999%}.w3-col.m4,.w3-third{width:33.33333%}
.w3-col.m5{width:41.66666%}.w3-col.m6,.w3-half{width:49.99999%}.w3-col.m7{width:58.33333%}.w3-col.m8,.w3-twothird{width:66.66666%}
.w3-col.m9,.w3-threequarter{width:74.99999%}.w3-col.m10{width:83.33333%}.w3-col.m11{width:91.66666%}.w3-col.m12{width:99.99999%}}
@media (min-width:993px){.w3-col.l1{width:8.33333%}.w3-col.l2{width:16.66666%}.w3-col.l3{width:24.99999%}.w3-col.l4{width:33.33333%}
.w3-col.l5{width:41.66666%}.w3-col.l6{width:49.99999%}.w3-col.l7{width:58.33333%}.w3-col.l8{width:66.66666%}
.w3-col.l9{width:74.99999%}.w3-col.l10{width:83.33333%}.w3-col.l11{width:91.66666%}.w3-col.l12{width:99.99999%}}
.w3-rest{overflow:hidden}.w3-stretch{margin-left:-16px;margin-right:-16px}
.w3-content,.w3-auto{margin-left:auto;margin-right:auto}.w3-content{max-width:980px}.w3-auto{max-width:1140px}
.w3-cell-row{display:table;width:100%}.w3-cell{display:table-cell}
.w3-cell-top{vertical-align:top}.w3-cell-middle{vertical-align:middle}.w3-cell-bottom{vertical-align:bottom}
.w3-hide{display:none!important}.w3-show-block,.w3-show{display:block!important}.w3-show-inline-block{display:inline-block!important}
@media (max-width:1205px){.w3-auto{max-width:95%}}
@media (max-width:600px){.w3-modal-content{margin:0 10px;width:auto!important}.w3-modal{padding-top:30px}
.w3-dropdown-hover.w3-mobile .w3-dropdown-content,.w3-dropdown-click.w3-mobile .w3-dropdown-content{position:relative}	
.w3-hide-small{display:none!important}.w3-mobile{display:block;width:100%!important}.w3-bar-item.w3-mobile,.w3-dropdown-hover.w3-mobile,.w3-dropdown-click.w3-mobile{text-align:center}
.w3-dropdown-hover.w3-mobile,.w3-dropdown-hover.w3-mobile .w3-btn,.w3-dropdown-hover.w3-mobile .w3-button,.w3-dropdown-click.w3-mobile,.w3-dropdown-click.w3-mobile .w3-btn,.w3-dropdown-click.w3-mobile .w3-button{width:100%}}
@media (max-width:768px){.w3-modal-content{width:500px}.w3-modal{padding-top:50px}}
@media (min-width:993px){.w3-modal-content{width:900px}.w3-hide-large{display:none!important}.w3-sidebar.w3-collapse{display:block!important}}
@media (max-width:992px) and (min-width:601px){.w3-hide-medium{display:none!important}}
@media (max-width:992px){.w3-sidebar.w3-collapse{display:none}.w3-main{margin-left:0!important;margin-right:0!important}.w3-auto{max-width:100%}}
.w3-top,.w3-bottom{position:fixed;width:100%;z-index:1}.w3-top{top:0}.w3-bottom{bottom:0}
.w3-overlay{position:fixed;display:none;width:100%;height:100%;top:0;left:0;right:0;bottom:0;background-color:rgba(0,0,0,0.5);z-index:2}
.w3-display-topleft{position:absolute;left:0;top:0}.w3-display-topright{position:absolute;right:0;top:0}
.w3-display-bottomleft{position:absolute;left:0;bottom:0}.w3-display-bottomright{position:absolute;right:0;bottom:0}
.w3-display-middle{position:absolute;top:50%;left:50%;transform:translate(-50%,-50%);-ms-transform:translate(-50%,-50%)}
.w3-display-left{position:absolute;top:50%;left:0%;transform:translate(0%,-50%);-ms-transform:translate(-0%,-50%)}
.w3-display-right{position:absolute;top:50%;right:0%;transform:translate(0%,-50%);-ms-transform:translate(0%,-50%)}
.w3-display-topmiddle{position:absolute;left:50%;top:0;transform:translate(-50%,0%);-ms-transform:translate(-50%,0%)}
.w3-display-bottommiddle{position:absolute;left:50%;bottom:0;transform:translate(-50%,0%);-ms-transform:translate(-50%,0%)}
.w3-display-container:hover .w3-display-hover{display:block}.w3-display-container:hover span.w3-display-hover{display:inline-block}.w3-display-hover{display:none}
.w3-display-position{position:absolute}
.w3-circle{border-radius:50%}
.w3-round-small{border-radius:2px}.w3-round,.w3-round-medium{border-radius:4px}.w3-round-large{border-radius:8px}.w3-round-xlarge{border-radius:16px}.w3-round-xxlarge{border-radius:32px}
.w3-row-padding,.w3-row-padding>.w3-half,.w3-row-padding>.w3-third,.w3-row-padding>.w3-twothird,.w3-row-padding>.w3-threequarter,.w3-row-padding>.w3-quarter,.w3-row-padding>.w3-col{padding:0 8px}
.w3-container,.w3-panel{padding:0.01em 16px}.w3-panel{margin-top:16px;margin-bottom:16px}
.w3-code,.w3-codespan{font-family:Consolas,"courier new";font-size:16px}
.w3-code{width:auto;background-color:#fff;padding:8px 12px;border-left:4px solid #4CAF50;word-wrap:break-word}
.w3-codespan{color:crimson;background-color:#f1f1f1;padding-left:4px;padding-right:4px;font-size:110%}
.w3-card,.w3-card-2{box-shadow:0 2px 5px 0 rgba(0,0,0,0.16),0 2px 10px 0 rgba(0,0,0,0.12)}
.w3-card-4,.w3-hover-shadow:hover{box-shadow:0 4px 10px 0 rgba(0,0,0,0.2),0 4px 20px 0 rgba(0,0,0,0.19)}
.w3-spin{animation:w3-spin 2s infinite linear}@keyframes w3-spin{0%{transform:rotate(0deg)}100%{transform:rotate(359deg)}}
.w3-animate-fading{animation:fading 10s infinite}@keyframes fading{0%{opacity:0}50%{opacity:1}100%{opacity:0}}
.w3-animate-opacity{animation:opac 0.8s}@keyframes opac{from{opacity:0} to{opacity:1}}
.w3-animate-top{position:relative;animation:animatetop 0.4s}@keyframes animatetop{from{top:-300px;opacity:0} to{top:0;opacity:1}}
.w3-animate-left{position:relative;animation:animateleft 0.4s}@keyframes animateleft{from{left:-300px;opacity:0} to{left:0;opacity:1}}
.w3-animate-right{position:relative;animation:animateright 0.4s}@keyframes animateright{from{right:-300px;opacity:0} to{right:0;opacity:1}}
.w3-animate-bottom{position:relative;animation:animatebottom 0.4s}@keyframes animatebottom{from{bottom:-300px;opacity:0} to{bottom:0;opacity:1}}
.w3-animate-zoom {animation:animatezoom 0.6s}@keyframes animatezoom{from{transform:scale(0)} to{transform:scale(1)}}
.w3-animate-input{transition:width 0.4s ease-in-out}.w3-animate-input:focus{width:100%!important}
.w3-opacity,.w3-hover-opacity:hover{opacity:0.60}.w3-opacity-off,.w3-hover-opacity-off:hover{opacity:1}
.w3-opacity-max{opacity:0.25}.w3-opacity-min{opacity:0.75}
.w3-greyscale-max,.w3-grayscale-max,.w3-hover-greyscale:hover,.w3-hover-grayscale:hover{filter:grayscale(100%)}
.w3-greyscale,.w3-grayscale{filter:grayscale(75%)}.w3-greyscale-min,.w3-grayscale-min{filter:grayscale(50%)}
.w3-sepia{filter:sepia(75%)}.w3-sepia-max,.w3-hover-sepia:hover{filter:sepia(100%)}.w3-sepia-min{filter:sepia(50%)}
.w3-tiny{font-size:10px!important}.w3-small{font-size:12px!important}.w3-medium{font-size:15px!important}.w3-large{font-size:18px!important}
.w3-xlarge{font-size:24px!important}.w3-xxlarge{font-size:36px!important}.w3-xxxlarge{font-size:48px!important}.w3-jumbo{font-size:64px!important}
.w3-left-align{text-align:left!important}.w3-right-align{text-align:right!important}.w3-justify{text-align:justify!important}.w3-center{text-align:center!important}
.w3-border-0{border:0!important}.w3-border{border:1px solid #ccc!important}

.w3-button:hover{color:#000!important;background-color:#ccc!important}


</style>





<style> 
textarea {
  width: 99%;
  height: 250px;
  padding: 15px 20px;
  box-sizing: border-box;
  border: 2px solid #ccc;
  border-radius: 9px;
  background-color: #f8f8f8;
  font-size: 24px;
  resize: none;
}
</style>
</head>
<body>
  <script>
 
    var newArray1;
    var newArray2;
    var first_letter;
    var remaining_letters=' ';
    var pause=1;
    var mycount=0; 
    
    
    var typing_speed=10;//default value of typing speed (slow )
   
       
      
      // can set this value for changing clock speed
     var master_clock = 100; // milliseconds in which each text is send  
     
     
     
     
     
      
    function update_main_log(){
		 console.log("key up done" )
		 // Taking content value of TEXTAREA into main_log array
		 main_log = document.getElementById("txtcw").value;
		  console.log(main_log )


		}
		
		
		
		
		
		
// starting timer with interval = refresh_time
let master_timer = setInterval(watchdog,master_clock);


function watchdog(){
  mycount=mycount+1;
   console.log(mycount)
   
   // getting user set speed
   if(mycount >=typing_speed){ 
	   
	   mytimer();
	   mycount=0;
	   
	    }

		
}




function mytimer() {
// Call a function repetatively with 1 Second interval

  
  
  
  
  if(pause == 0){ 
document.getElementById("status").innerHTML="PAUSE CW";
//document.getElementById("txtcw").focus();
 }
 
if(pause == 1)
 {	 
document.getElementById("status").innerHTML="CONTINUE >>";
//document.getElementById("txtcw").focus();
 }
  
  

  
  
  
  
  
  
  
  if(document.getElementById("txtcw").value.length >=1 && pause == 0 ){
   
 newArray1 = Array.from(document.getElementById("txtcw").value);

 
  // finding first charactor of this array
    first_letter = newArray1[0].toString();
    
    
    
    
    
    // send this first character to ESP12 
     sendData(first_letter);
    console.log("Sending  CW : " +  first_letter )
    
    
    
    
    
    
    
    // removing this first charactor from newArray1 also
   newArray1.shift();
    
    
    remaining_letters = newArray1.join('');
    // Updating TEXTAREA with shifted text
 document.getElementById("txtcw").value = remaining_letters;
 // document.getElementById("txtcw").focus();
 
 
  
     console.log(remaining_letters)
     console.log("length is : " + remaining_letters.length)
  
  
       
  // Auto Pause when all text is send as cw     
  // if(remaining_letters.length == 0){
  // pause=1;  
  //  }else{ pause=0; }
    
   }// if






 } // timer closing
 
 
 
 
 

  function pause_button(){
	  
     console.log("button pressed")
	
	  if(pause == 0){
		   pause = 1;
		            }else{ pause = 0; }
		            
		            
	// document.getElementById("txtcw").focus();	            
		            
  }// pause/continue button












  </script>
    	
	
	
	
	
	
	

	
	
	

<h3 id="sendreceipt" >AVE RnD  cw keyer Ver.1.2</h3>



<form>
  <textarea  id="txtcw" onkeyup="update_main_log()"> </textarea>
   
</form>

<button class="w3-btn w3-xlarge w3-white w3-border w3-round-large" id="status" onclick="pause_button()"> PAUSE CW </button>
	&nbsp;	&nbsp;	&nbsp;
<div>
	
<p></p> 
<p></p>  
<button class="w3-btn w3-white w3-border w3-round-large" type="button" onclick="edit_1()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_1">
 &nbsp;
<button class="w3-btn  w3-white w3-border w3-round-large" type="button" onclick="edit_2()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_2">
<p></p>   
</div>

<div>
<p></p> 
<p></p>  
<button class="w3-btn  w3-white w3-border w3-round-large" type="button" onclick="edit_3()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_3">
&nbsp; 
<button class="w3-btn  w3-white w3-border w3-round-large" type="button" onclick="edit_4()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_4">
</div>

<div>
<p></p> 
<p></p> 
<button class="w3-btn  w3-white w3-border w3-round-large" type="button" onclick="edit_5()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_5">
 &nbsp; 
<button class="w3-btn  w3-white w3-border w3-round-large" type="button" onclick="edit_6()"> Go >> </button>
<input class="w3-btn  w3-white w3-border w3-round-large"  type="text" id="edit_txt_6">
<p></p>   
</div>




 <fieldset class="w3-left-align">
	 <br>
  <legend><b>[ &#9967; Settings ]</b></legend>

  <input onchange="change_tone()" oninput="show_sweeped_tone()" id="sidetone" type="range" min="50" max="2000" value="500" class="w3-col m5" >
  <br><br>
  Change SIDE TONE frequecy: <b><i id="side_tone">???</i></b> Hertz
  <br>
  Saved SIDE TONE frequency : <font color="blue"><b><i id="receipttone"></i></b></font> Hertz
<br><br>
  
  
   <p></p>
   <p></p>
   <br>
    <input onchange="change_wpm()" oninput="show_sweeped_wpm()" id="speed" type="range" min="40" max="150" value="90" class="w3-col m5" >
    <br><br>
  Change DIT time : <b><i id="ditime">???</i></b> Milli Second
  <br>
  Saved DIT time : <font color="blue"><b><i id="receiptwpm"></i></b></font> Milli Second
   <p></p>
  <br>
  
     <p></p>
   <p></p>
   <br>
    
  <label for="ca">Choose Typing Speed </label>
  <select name="ca" id="ca" onchange="change_speed()" class="w3-select">
    <option value=15>Very Slow</option>
    <option value=10>Slow</option>
    <option value=6>Medium</option>
    <option value=4>High</option>
    <option value=2 >Very High</option>
  </select>


   <br>
   
   <p></p>  
 </fieldset>

<script>
  
function show_sweeped_wpm(){
  // only diplay :  instantanious selected values of sweep selector
document.getElementById("ditime").innerHTML = document.getElementById("speed").value; 
  
} 

function show_sweeped_tone(){
  // only diplay :  instantanious selected values of frequency selector
document.getElementById("side_tone").innerHTML = document.getElementById("sidetone").value; 
  
} 


    
function change_wpm(){
  //up on final select from sweep bar..send and set new wpm in eeprom
document.getElementById("ditime").innerHTML = document.getElementById("speed").value;
//document.getElementById('txtcw').focus();
// sending milliseconds value
sendWpm(document.getElementById("speed").value);

}

function change_tone(){
  //up on final select from sweep bar..send and set new wpm in eeprom
document.getElementById("side_tone").innerHTML = document.getElementById("sidetone").value;
//document.getElementById('txtcw').focus();
// sending frequency value
 sendTone(document.getElementById("sidetone").value);

}

////////////////////////

function change_speed(){
typing_speed = 	document.getElementById("ca").value; // setting new typing speed
sendSpeed(document.getElementById("ca").value); // sending new speed value to eeprom via ajax
	
}


</script>




















<script>
function edit_1(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_1").value;
  // document.getElementById("txtcw").focus();
}
function edit_2(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_2").value;
  //document.getElementById("txtcw").focus();
}
function edit_3(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_3").value;
 // document.getElementById("txtcw").focus();
}
function edit_4(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_4").value;
 // document.getElementById("txtcw").focus();
}
function edit_5(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_5").value;
 // document.getElementById("txtcw").focus();
}
function edit_6(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_6").value;
 // document.getElementById("txtcw").focus();
}
</script>





<script>
// ALL FUNCTIONS TO SEND DATA OVER AJAX

function sendData(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      
      document.getElementById("sendreceipt").innerHTML ="CW ><font color=blue><b> " + this.responseText +"</b></font>";
      
    }
  };
  xhttp.open("GET", "cwtxt?mytxt="+txt, true);
  xhttp.send();
}



function sendWpm(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receiptwpm").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "wpmtxt?mytxt="+txt, true);
  xhttp.send();
}


function sendTone(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receipttone").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "tonetxt?mytxt="+txt, true);
  xhttp.send();
}

///-----------------//////////////////

function sendSpeed(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      
typing_speed=this.responseText;
      
    }
  };
  xhttp.open("GET", "speedtxt?mytxt="+txt, true);
  xhttp.send();
}

 </script>




<script>
 const myTimeout = setTimeout(getSavedWpm, 5000);

// Exicuite the below function after the TIMESET = 5 Seconds // for retriving Saved WPM milliseconds for display purpose
 
 function getSavedWpm(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receiptwpm").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "wpmback?mytxt=1", true);
  xhttp.send();  
 }
 
 </script>


  <script>
 const myTimeout1 = setTimeout(getSavedTone, 7000);

// Exicuite the below function after the TIMESET = 7 Seconds // for retriving Saved Side tone frequency (Heartz)for display purpose
 
 function getSavedTone(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receipttone").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "toneback?mytxt=1", true);
  xhttp.send();  
 }
 
 </script>



  <script>
 const myTimeout2 = setTimeout(getSavedtypespeed, 9000);

// Exicuite the below function after the TIMESET = 9 Seconds // for retriving Saved typingspeed (example: 2)for display purpose
 
 function getSavedtypespeed(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {

   typing_speed=this.responseText; // settting new type speed from eeprom (20)
   document.getElementById("ca").value=typing_speed; // u[dating selected typing speed in selection list
    
    }
  };
  xhttp.open("GET", "speedback?mytxt=1", true);
  xhttp.send();  
 }
 
 </script>




</body>
</html>
)=====";
