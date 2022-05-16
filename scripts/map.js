function myMap() {
    var mapProp= {
      center:new google.maps.LatLng(50.46643094259559, 30.497923498520827),
      zoom:12,
    };
    var map = new google.maps.Map(document.getElementById("googleMap"),mapProp);
    var marker = new google.maps.Marker({position: new google.maps.LatLng(50.46643094259559, 30.497923498520827)});
    marker.setMap(map);
    }