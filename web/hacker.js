
async function createHackerUsingPHP() {
    const name = document.getElementById('input-hacker').value;
    const status = document.getElementById('status');

    if (!name) {
        status.innerText = "Enter a name";
        return;
    }

    try { 
        const response = await fetch('PHP/create-hacker.php?v=1', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ name })
        });
        const result = await response.text();
        status.innerText = result;
        getHackersNode();
    } catch (error) {
        status.innerText = "PHP connection failed";
    }
}

async function createHackerUsingNode() {
    const name = document.getElementById('input-hacker').value;
    const status = document.getElementById('status');
    
    if (!name) {
        status.innerText = "Enter a name";
        return;
        }

    try {
        const response = await fetch('http://127.0.0.1:3000/create-hacker', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ name })
        });
        const result = await response.text();
        status.innerText = result;
        getHackersNode();
    } catch (error) {
        status.innerText = "Node connection failed";
    }
}

async function getHackersNode() {
    const list = document.getElementById('list-hackers');

    try {
        const response = await fetch('http://127.0.0.1:3000/get-hackers');
        const data = await response.json();
        list.innerHTML = "";

        if (data.length === 0) {
            list.innerHTML = "<p> Hackers is empty </p>";
            return;
        }

        data.forEach(hacker => {
            const item = document.createElement('div');
            item.className = 'hacker-class';
            item.innerHTML = `
                <strong> Name: </strong> ${hacker.name}
                | <a href="${hacker.name}/index.html" target="_blank"> View Hacker </a>
            `;
            list.appendChild(item);
        })

    } catch (error) {
        console.error("Error gettin hackers:", error);
        list.innerText = "Failed to load hacker list.";
    }
}

window.onload = getHackersNode;
