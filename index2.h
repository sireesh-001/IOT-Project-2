const char MAIN_page12[] PROGMEM = R"=====(
<!doctype html>
<html>
<head>
<title>IoT Motion detector</title>
<meta name=viewport content="width=device-width, initial-scale=1">
<h1 style=text-align:center;color:blue;font-size:2.5rem>IoT Motion Detector</h1>
<style>canvas{-moz-user-select:none;-webkit-user-select:none;-ms-user-select:none}#data_table{font-family:New Times Roman;border-collapse:collapse;width:100%;text-align:center;font-size:.8rem}#data_table td,#data_table th{border:3px solid #ddd;padding:15px}#data_table tr:nth-child(even){background-color:#faffff}#data_table tr:hover{background-color:#faffff}#data_table th{padding-top:20px;padding-bottom:20px;text-align:center;background-color:#190775;color:white}</style>
</head>
<body>
<div>
<table id=data_table>
<tr><th>Time</th><th>Activity</th></tr>
</table>
</div>
<br>
<br>
<script>var Avalues=[];var dateStamp=[];setInterval(function(){getData()},3000);function getData(){var a=new XMLHttpRequest();a.onreadystatechange=function(){if(this.readyState==4&&this.status==200){var e=new Date();var b=this.responseText;var g=JSON.parse(b);Avalues.push(g.Activity);dateStamp.push(e);var f=document.getElementById("data_table");var h=f.insertRow(1);var d=h.insertCell(0);var c=h.insertCell(1);d.innerHTML=e;c.innerHTML=g.Activity}};a.open("GET","read_data",true);a.send()};</script>
</body>
</html>
)=====";