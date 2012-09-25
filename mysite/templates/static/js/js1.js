//document.write("Hello JavaScript");
$(document).ready(function() {
	//$('tr:odd').addClass('form_odd');
	$('tr:nth-child(even)').addClass('form_odd');
});
function validate_login(form) {
	var returnValue = true;
	var username = form_login.username.value;
	var password = form_login.password.value;
	if (username.length < 4) {
		returnValue = false;
		alert("Your username must be at least \n4 characters long.\n Please try again.");
		form_login.username.focus();
		return returnValue;
	}
	if (password.length < 5) {
		returnValue = false;
		alert("Your password must be at least \n6 characters long.\n Please try again.");
		form_login.password.value = "";
		form_login.password.focus();
		return returnValue;
	}
	return returnValue;
}
/*
function displaymsg1()
{
	alert("Alert");
}

function displaymsg2()
{
	confirm("Confirm");
}


function displaymsg3()
{
	prompt("Name","chengl");
}

function for1()
{
	var i=0;
	for (; i<=10;i++)
	{
		document.write("The number is " + i);
		document.write("<br />");
	}
}

function js_try()
{
	var x=prompt("Enter a number between 0 and 10:","");
	try
	{
		if(x>10)
			throw "Err1";
		else if(x<0)
			throw "Err2";
	}
	catch(er)
	{
		if(er=="Err1")
			alert("Error! The value is too high");
		if(er == "Err2")
			alert("Error! The value is too low");
		return false;
	}
}
*/
