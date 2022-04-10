function myFunction() {
  //x is name placeholder
  var x = document.getElementById("playerName").value;

  let name = x;
  document.getElementById('playerName').innerHTML = name;
  
  console.log(x);
  if (x === ""){
    alert("Player Name must be filled out!");
  }else{
   window.location.href='menu.html'; 
  }
}
