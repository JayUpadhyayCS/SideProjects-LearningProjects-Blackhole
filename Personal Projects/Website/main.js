let getTime=function()
{
    var today = new Date();
    var date = today.getFullYear()+'-'+(today.getMonth()+1)+'-'+today.getDate();
    var hour=today.getHours();
    var sec=today.getSeconds();
    var min=today.getMinutes()
    hour=notMilitaryTime(hour);
    hour=addZero(hour);
   min= addZero(min);
    sec=addZero(sec);
    
    var time = hour + ":" + min + ":" + sec;
    var dateTime = date+' '+time;
    alert(dateTime);
}

let addZero=function(thing)
{

    if(thing<10)
    {
        thing="0"+thing;
    }
    return thing;

}
let notMilitaryTime=function(thing)
{
    if(thing>12)
    {
        thing-=12;
    }
    return thing;
}