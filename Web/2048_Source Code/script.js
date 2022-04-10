 //minimum dapat ng size is 2

let size = sessionStorage.getItem('gridSize')
document.getElementById("board").style.width = (size*100).toString()+"px";
document.getElementById("board").style.height = (size*100).toString()+"px";
let table = new Array
let score = 0
let endLessMode = sessionStorage.getItem('endless')
let gameOver = false
let gameFinish = false
//let music = sessionStorage.getItem('music')
let username = sessionStorage.getItem('username')

document.getElementById("name").innerHTML = username

console.log("Endless Mode:", endLessMode)
console.log("Size:", size)
if(endLessMode === "true"){
    document.getElementById("endlessMode").innerHTML = "On"
} else{
    document.getElementById("endlessMode").innerHTML = "Off"
}

//Kung pwede ka pa ba magmove in different direction
// default natin true muna lahat
// pag nag false na to lahat ibig sabihin wala ng moves left
/// therefore gameover na
//tells if move is available
//           left   right up    down
let moves = [true,true,true,true]

for (let x = 0; x < size; x++) {
    table[x] = new Array
    for (let y = 0; y < size; y++) {
        table[x][y] = 0
    }
}

//generate 2 or 4
function generate(){
    let num = Math.random()
    num = num > .5 ? 2 : 4
    return num
}

//recursion
function putNumTable(){
  
    let ranX = Math.floor(Math.random() * size);
    let ranY = Math.floor(Math.random() * size);

    if(table[ranX][ranY] === 0){
        table[ranX][ranY] = generate()
    } else{
        // what if all table is != 0?
        putNumTable()
    }
}

// Just to reset the table tiles
// para ma fix yung bug na nagspawn over sa prev table
function clearTable(parent){
    var child = parent.lastElementChild; 
    while (child) {
        parent.removeChild(child);
        child = parent.lastElementChild;
    }
}

// Update the table sa changes ng table[][] var natin
function updateGameTable(){
    let parent = document.getElementById("board");
    clearTable(parent)

    for (let r = 0; r < size; r++) {
        for (let c = 0; c < size; c++) {
            let tile = document.createElement("div");
            tile.classList.add("tile");
            tile.classList.add("x2");
            let num = table[r][c]
            if (num > 0) {
                tile.innerText = table[r][c]
            }
            document.getElementById("board").append(tile)
        }
    }
    //console.log(score)
}

// Removes the zeros sa isang array
function filterZero(arr){
    return arr.filter(num => num != 0);
}

// Moves all the non zero to left in the given 1D array 
// Add if may same number, tas append na lang new zeros
function slide(arr){
    
    arr = filterZero(arr); 
    for (let i = 0; i < arr.length-1; i++){
        if (arr[i] == arr[i+1]) {
            arr[i] *= 2;
						
            // ENDLESS MODE CONDITION
            if(endLessMode !== 'true'){
                if(arr[i] === 2048){
                    console.log("Game Finish");
										alert("Game Finish")
                    gameFinish = true
										window.location.replace("/leaderboard.html");
                }
							console.log("end")
            }
      
            arr[i+1] = 0;
            // May score counter 
            score += arr[i];
            document.getElementById("score").innerHTML = score
           
        }
    } 
    arr = filterZero(arr); 
    while (arr.length < size) {
        arr.push(0);
    } 
    return arr;
}


//check if same table when theres a movement 
// if same don't generate new number
function checkSnapshotTable(copyTable,copyTable2){
    if(arraysEqual(copyTable,copyTable2)){
        return false
    }else{
        return true
    }
}


// Di ko ako makapagcopy ng array, di to nagana v = array 
// kaya hinardcode ko ang pag copy
function copyTable(){
    let copyTable = new Array
    for (let x = 0; x < size; x++) {

        copyTable[x] = new Array
        for (let y = 0; y < size; y++) {
            copyTable[x][y] = table[x][y]
        }

    }
    
    return copyTable
}


// For some reason di ko gumagana yung condition na array == array
// so I have to hard code it
function arraysEqual(a, b) {
    for (let x = 0; x < size; x++) {
       
        for (let y = 0; y < size; y++) {
            if(a[x][y] === b[x][y]){
                //
            }else{
                return false
            }
        }
    }

    return true
    
}

// function moveLeft() {
//     copy = copyTable()

//     for (let r = 0; r < size; r++) {
//         let row = table[r];
//         row = slide(row);
//         table[r] = row;
//     }

//     copy2 = copyTable()


//     if(checkSnapshotTable(copy,copy2)){
//         putNumTable()
//         for (let x = 0; x < 4; x++){
//             moves[x] = true
//         }
//     }else{
//         moves[0] = false
//     }

//     updateGameTable()
// }

// function moveRight() {
//     copy = copyTable()
//     for (let r = 0; r < size; r++) {
//         let row = table[r];         
//         row.reverse();             
//         row = slide(row)     
//         //note: slide is pushing everything to the left so we need to reverse the array       
//         table[r] = row.reverse();   
//     }
    
//     copy2 = copyTable()
//     if(checkSnapshotTable(copy,copy2)){
//         putNumTable()
//         for (let x = 0; x < 4; x++){
//             moves[x] = true
//         }
//     }else{
//         moves[1] = false
//     }

//     updateGameTable()
// }



// function moveUp() {
//     copy = copyTable()
//     for (let c = 0; c < size; c++) {
//         // create coll and populate it with column from the table
//         let col = new Array
//         for (let x = 0; x < size; x++){
//            col.push(table[x][c])
//         }

//         col = slide(col)
  
//         for (let r = 0; r < size; r++){
//             table[r][c] = col[r];
           
//         }
//     }

//     copy2 = copyTable()
//     if(checkSnapshotTable(copy,copy2)){
//         putNumTable()
//         for (let x = 0; x < 4; x++){
//             moves[x] = true
//         }
//     }else{
//         moves[2] = false
//     }
//     updateGameTable()
// }

// function moveDown() {
//     copy = copyTable()
//     for (let c = 0; c < size; c++) {
//         let col = new Array
//         for (let x = 0; x < size; x++){
//            col.push(table[x][c])
//         }
//         col.reverse();
//         col = slide(col);
//         col.reverse();

//         for (let r = 0; r < size; r++){
//             table[r][c] = col[r];
//         }
//     }
//     copy2 = copyTable()
//     if(checkSnapshotTable(copy,copy2)){
//         putNumTable()
        
//         for (let x = 0; x < 4; x++){
//             moves[x] = true
//         }
//     }else{
//         moves[3] = false
//     }
  
//     updateGameTable()
// }


//Provides the sound effects for the moving number blocks
document.addEventListener('keydown', function(e) {
  if(e.keyCode == 37 || e.keyCode == 38 || e.keyCode == 39 || e.keyCode == 40){
  document.getElementById('audio').play();
  }
});

// Our controls
// document.addEventListener('keyup', (e) => {
//     if (e.code == "ArrowLeft") {
//       moveLeft()

//     }
//     else if (e.code == "ArrowRight") {
        
//       moveRight()

//     }
//     else if (e.code == "ArrowUp") {
        
//       moveUp()
      
//     }
//     else if (e.code == "ArrowDown") {
        
//       moveDown()

//     } //document.getElementById("score").innerText = score;

//     console.log(moves);
//     // GAME OVER CONDITION
//     if(moves[0] === false && 
//         moves[1] === false && 
//         moves[2] === false && 
//         moves[3] === false){
//             gameOver = true
         
//             alert("GAME OVER, FINAL SCORE: "+ score)
			
//             sessionStorage.setItem("score", score)
//             setCookie(username,score)
// 						window.location.replace("/menu.html");
            
//     }
// })

var invoker = {
    down: function() {
      copy = copyTable()
    for (let c = 0; c < size; c++) {
        let col = new Array
        for (let x = 0; x < size; x++){
           col.push(table[x][c])
        }
        col.reverse();
        col = slide(col);
        col.reverse();

        for (let r = 0; r < size; r++){
            table[r][c] = col[r];
        }
    }
    copy2 = copyTable()
    if(checkSnapshotTable(copy,copy2)){
        putNumTable()
        moves[3] = true
    }else{
        moves[3] = false
    }
    updateGameTable()
    },

  
    up: function() {
      copy = copyTable()
      for (let c = 0; c < size; c++) {
        // create coll and populate it with column from the table
        let col = new Array
        for (let x = 0; x < size; x++){
           col.push(table[x][c])
        }

        col = slide(col)
        for (let r = 0; r < size; r++){
            table[r][c] = col[r];
        }
    }
    copy2 = copyTable()
    if(checkSnapshotTable(copy,copy2)){
        putNumTable()
        moves[2] = true
    }else{
        moves[2] = false
    }
    updateGameTable()      
    },

  
    left: function() {
      copy = copyTable()
      for (let r = 0; r < size; r++) {
        let row = table[r];
        row = slide(row);
        table[r] = row;
    }

    copy2 = copyTable()
    if(checkSnapshotTable(copy,copy2)){
        putNumTable()
        moves[0] = true
    }else{ 
        moves[0] = false
    }
    updateGameTable()
    },

  
    right: function() {
        copy = copyTable()
    for (let r = 0; r < size; r++) {
        let row = table[r];         
        row.reverse();             
        row = slide(row)     
        //note: slide is pushing everything to the left so we need to reverse the array  
        table[r] = row.reverse();   
    }
    copy2 = copyTable()
    if(checkSnapshotTable(copy,copy2)){
        putNumTable()
        moves[1] = true
    }else{
        moves[1] = false
    }
    updateGameTable()
    }
}

var manager = {
    execute: function(name) {
        if (name in invoker) {
            return invoker[name].apply(invoker);
        }
        return false;
    }
}

// Our controls
document.addEventListener('keyup', (e) => {
    if (e.code == "ArrowLeft") {
      
      manager.execute("left")
    }
    else if (e.code == "ArrowRight") {
        
      manager.execute("right")

    }
    else if (e.code == "ArrowUp") {
        
      manager.execute("up")
      
    }
    else if (e.code == "ArrowDown") {
        
      manager.execute("down")

    }
    //document.getElementById("score").innerText = score;

    //consoled.log(moves);
    // GAME OVER CONDITION
    if(moves[0] === false && 
        moves[1] === false && 
        moves[2] === false && 
        moves[3] === false){
        alert("GAME OVER, FINAL SCORE: "+ score)
			
        sessionStorage.setItem("score", score)
        setCookie(username,score)
		  window.location.replace("/menu.html");
    }
})

// MAIN FUNCTION NG GAME
function game(){
    putNumTable()
    putNumTable()
    
    updateGameTable()
}


game()

function setCookie(cname, cscore) {
    let days = 30
    const d = new Date();
    d.setTime(d.getTime() + (days*24*60*60*1000));
    let expires = "expires="+ d.toUTCString();
    document.cookie = cname + "=" + cscore + ";" + expires + ";path=/";
}
