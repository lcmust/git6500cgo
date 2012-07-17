<?php
echo("<hr>");
$file = $_SERVER['PHP_SELF'];
$user = $_SERVER['HTTP_USER_AGENT'];
$address = $_SERVER['REMOTE_ADDR'];

echo("equite_path:<b>$file</b>");
echo("<br/>");
echo("client web:<b>$user</b>");
echo("<br/>");
echo("client IP:<b>$address</b>");
$client_info = "$file".' '."$user".' '."$address";
echo("<br/>");
echo("<i>$client_info</i>");
echo("<hr>");
?>
