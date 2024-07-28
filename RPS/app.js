let userScore=0;
let compScore=0;

let us=document.querySelector("#user-score");
let cs=document.querySelector("#comp-score");

const choices=document.querySelectorAll(".choice");
const msg=document.querySelector("#msg");

const geneCompChoice=()=>{
    const options=["rock","scissor","paper"];
    const ranIdx=Math.floor(Math.random()*3);
    return options[ranIdx];
}

const drawGame=()=>{
    console.log("Game was drawn");
    msg.innerText="Game was drawn. Play Again";
    msg.style.backgroundColor="#081b31";
};

const showWinner=(userWin,userChoice,compChoice)=>{
    if(userWin){
        console.log("You Win");
        msg.innerText=`You Win! ${userChoice} beats ${compChoice} `;
        msg.style.backgroundColor="green";
        us.innerText=++userScore;
    }
    else{
         console.log("You Lose");
         msg.innerText=`You Lose! ${compChoice} beats ${userChoice} `;
         msg.style.backgroundColor="red";
         cs.innerText=++compScore;
    }
}

const playGame=(userChoice)=>{
    console.log("user choice =",userChoice);
    const compChoice=geneCompChoice();
    console.log("Comp Choice= ",compChoice);

    if(userChoice===compChoice){
        drawGame();
    }else{
        let userWin=true;
        if(userChoice==="rock"){
            userWin=compChoice==="paper"?false:true;
        }else if(userChoice==="paper"){
            userWin=compChoice==="scissor"?false:true;
        }else{
            userWin=compChoice=="rock"?false:true;
        }
        showWinner(userWin,userChoice,compChoice);
    }

}

choices.forEach((choice)=>{
    choice.addEventListener("click",()=>{
        const userChoice=choice.getAttribute("id");
        playGame(userChoice);
    });
});