//document.write("Hello JavaScript");
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
