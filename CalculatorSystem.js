function calculate() {
    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let operation = document.getElementById("operation").value;

    fetch(`/cgi-bin/calculator.cgi?num1=${num1}&num2=${num2}&operation=${operation}`)
        .then(response => response.text())
        .then(data => document.getElementById("result").textContent = data)
        .catch(error => console.error("Error:", error));
}
