function checkDate(date1, date2, regi1, regi2){
    let d1 = new Date(date1), d2 = new Date(date2), r1 = new Date(regi1), r2 = new Date(regi2);
    if(d1 > d2)
        return true;
    else if(d1 < d2)
        return false;
    else{
        if(r1 > r2)
            return true;
        else
            return false;
    }
}

//【連想配列】
let data = [
    { key: 'A', date: '2023/05/01', regiDate: '2023/04/25' },
    { key: 'B', date: '2023/05/02', regiDate: '2023/04/26' },
    { key: 'C', date: '2023/05/03', regiDate: '2023/04/27' },
    { key: 'A', date: '2023/05/04', regiDate: '2023/04/28' },
    { key: 'D', date: '2023/05/05', regiDate: '2023/04/29' },
    { key: 'B', date: '2023/05/02', regiDate: '2023/04/30' },
    { key: 'E', date: '2023/05/07', regiDate: '2023/05/01' },
    { key: 'D', date: '2023/05/08', regiDate: '2023/05/02' },
    { key: 'C', date: '2023/05/09', regiDate: '2023/05/03' },
    { key: 'A', date: '2023/05/04', regiDate: '2023/05/04' }
];

let array = [];

for(let i = 0; i < data.length - 1; i++){
    for(let j = i + 1; j < data.length; j++){
        if(data[i].key == data[j].key){
            if(checkDate(data[i].date, data[j].date, data[i].regiDate, data[j].regiDate) == true)
                array.push(j);
            else
                array.push(i);
        } 
    }
}

let newArray = [...new Set(array)];
newArray.sort((a, b) => b - a);

for(let i = 0; i < newArray.length; i++)
    data.splice(newArray[i], 1)

console.log(data);
    /*【条件】
    1. 同じ "key" の値を持つ要素を、1つだけ配列に残します。
    2. "date" が最新の要素を残します。
    3. "date" が同じ場合は、"regiDate" が最新の要素を残します。*/