const char MAIN_page1[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Health Monitoring System</title>
<!-- Bootstrap -->

<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link href="https://fonts.googleapis.com/css?family=Odibee+Sans&display=swap" rel="stylesheet">
    <style>
     #map {
      height: 300px;  /* The height is 400 pixels */
      width: 100%;  /* The width is the width of the web page */
     }
     body{
      background:linear-gradient(135deg, #fcdf8a 0%,#f38381 100%);
     }
     .header{
      background-color: #FFFEFF;
      color: #f38381;
      font-family: 'Odibee Sans', cursive;
      letter-spacing: 1.2em;
     }
  </style>
</head>
<body>
    
<!-- Main HTML CODE -->
<div class="header shadow-sm p-3 mb-4">
  <p class="display-3  text-center ">Health Monitoring System</p>
</div>

<div class="container">
    <div class="row d-flex justify-content-center">
        <div class="col-auto mb-1">
                <div class="card shadow-sm" style="width: 15.5rem; height: 20rem;">
                        <p class="card-header">Temparature</p>
                        <img  src="https://drive.google.com/uc?export=view&id=1VQSrwwtRKU6k-7_tsjr6YnS4bmhh19Xr" class="card-img-top p-2" height="150px" alt="temparature"> 
                        
                        <div class="card-body">
                          <p class="card-text alert alert-warning h4 text-center" role="alert" id="temp">0 <sup>o</sup>C</p>
                        </div>
                </div>
        </div>
        <div class="col-auto mb-1">
                <div class="card shadow-sm" style="width: 15.5rem; height: 20rem;">
                        <p class="card-header">BPM</p>
                        <img  src="https://drive.google.com/uc?export=view&id=1waeTqU67ozVnDAndJ22-inN16Z_0-e-M" class="card-img-top p-2" height="150px" alt="BPM"> 
                        <div class="card-body">
                          <p class="card-text alert alert-success h4 text-center" role="alert" id="bpm">bpm</p>
                        </div>
                </div>
        </div>
        <div class="col-auto mb-1">
                <div class="card shadow-sm" style="width: 15.5rem; height: 20rem;">
                        <p class="card-header">Smoke</p>
                        <img  src="https://drive.google.com/uc?export=view&id=1ByTw2H1_FJnLuDHOgRYxJv-5B4Wy7bp0" class="card-img-top p-2" height="150px" alt="smoke"> 
                        <div class="card-body">
                          <p class="card-text alert alert-danger h5 text-center" role="alert" id="smoke"></p>
                        </div>
                </div>
        </div>
        <div class="card-body">
                         <a href="/motion"> <p style="width: 15.5rem; height: 10rem;" class="card-text alert alert-danger h5 text-center" role="alert" id="smoke">Motion test</p></a>
                        </div>
    </div>

    <!-- Location -->
    <div class=" my-5 bg-light p-2 rounded text-center shadow">
            <p class="h4 text-dark" id="ecg">ECG DATA</p>
            <!-- <img src="./heart.svg" alt="ecg"> -->
            <canvas id="myChart" width="400" height="130"></canvas>

        </div>

    <!-- Location -->
    <div class=" my-5 bg-light p-2 rounded text-center shadow">
            <p class="h4 text-dark" >LOCATION</p>
            <!-- <img src="./map.jpg" alt="ecg"> -->
            <div id="map"></div>  
    </div>
</div>


<script>
var Avalues=[];
var Avalues1=[];
var dateStamp=[];
setInterval(function(){getData()},3000);
function getData(){var a=new XMLHttpRequest();
a.onreadystatechange=function(){if(this.readyState==4&&this.status==200){var c=new Date();
var e=this.responseText;
var b=JSON.parse(e);
var keys = Object.keys(b);
const key1 = keys[0];
var x = String(b[key1]);
const key2 = keys[1];
var y = String(b[key2]);
const key3 = keys[2];
var z = String(b[key3]);
//Avalues.push(e.Activity);
Avalues.push(x);
var d=document.getElementById("smoke");
d.innerHTML=y;
var d1=document.getElementById("bpm");
d1.innerHTML=x+" BPM";
var d2=document.getElementById("temp");
d2.innerHTML=z+" C";
var ctx = document.getElementById('myChart').getContext('2d');
    var chart = new Chart(ctx, {
    type: 'line',
    data: {
         labels: Avalues,
        datasets: [{
            label: 'ECG',
            backgroundColor: 'rgba(255, 255, 255, 0.0)',
            borderColor: 'rgb(255, 99, 132)',
            data: Avalues
        }]
    },
    options: {animation: {
        duration: 50,
        easing:'easeInBack'
    },
    elements: {
            line: {
                tension: .1 
            },
            point:{
                        radius: 0}
        }    }
});
}};
a.open("GET","read_data1",true);
a.send()
};
</script>
<script>
   function myMap() {
var mapProp= {
  center:new google.maps.LatLng(18.870163,79.448354),
  zoom: 14, 
};
      // The map, centered at location
      var map = new google.maps.Map(
          document.getElementById('map'), mapProp);
      // The marker, positioned at location
      var marker = new google.maps.Marker({position: new google.maps.LatLng(18.870163,79.448354), map: map});
     
    }
        </script>
        <script async defer
        src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBiHQpPumKYWDgZhs2xIcZ4ku179L63p2Q&callback=myMap">
        </script>
<!-- Bootstrap Scripts -->
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>
</body>
</html>
)=====";
