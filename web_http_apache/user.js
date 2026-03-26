
function printUsers()
{
    fetch(`users.txt?t=${Date.now()}`)
        .then(response => {
            return response.text();
        })
        .then(data => {
            const display = document.getElementById('user-display');
            display.innerText = data; 
            console.log("Script response: user.txt injected successfully");
        })
        .catch(error => {
            console.error('Error:', error);
            document.getElementById('user-display').innerText = "Failed to load users.";
        });
}

async function addUserPHP() {
    const input = document.getElementById('user-input');
    const name = input.value;

    const params = new URLSearchParams();
    params.append('user', name);

    try {
        const response = await fetch('PHP/add-user.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded',
            },
            body: params
        });

        const data = await response.text();
        console.log("PHP Response:", data);
        input.value = '';
        printUsers();

    } catch(error) {
        console.error('Error:', error);
    }
    
}

async function addUserNode() {
    const input = document.getElementById('user-input');
    const name = input.value;

    const params = new URLSearchParams();
    params.append('user', name);

    try {
        const response = await fetch('http://127.0.0.1:3000/add-user', {
            method: 'POST',
            body: params
        });

        const data = await response.text();
        console.log("Node response:", data);
        input.value = '';
        printUsers();

    } catch (error) {
        console.error('Error:', error);
    }
}

async function addUserFlask() {
    const input = document.getElementById('user-input');
    const name = input.value;

    const params = new URLSearchParams();
    params.append('user', name);

    try {
    
        const response = await fetch('http://127.0.0.1:5000/add-user', {
            method: 'POST',
            header: {
                'Content-Type': 'application/x-www-form-urlencoded',
            },
            body: params
        });
        
        const data = await response.text();
        console.log("Flask response:", data);
        input.value = '';
        printUsers();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function addUserDjango() {
    const input = document.getElementById('user-input');
    const name = input.value;

    const params = new URLSearchParams();
    params.append('user', name);

    try {
        const response = await fetch('http://127.0.0.1:8000/add-user/', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded',
            },
            body: params,
        });
        const data = await response.text();
        console.log("Django response:", data);
        input.value = '';
        printUsers();
    } catch (error) {
        console.error('Error:', error);
    }
}

/*  ============================================================================ */


async function getUsersMySQLPHP() {
    
    const display = document.getElementById('user-display-mysql');

    try {
        const response = await fetch('PHP/get-users-mysql.php');
        
        if (!response.ok) {
            throw new Error(`Server error:  ${response.status}`);
        }

        const data = await response.json();
        display.innerText = data.map(u => u.name_).join('\n');
        console.log("Fetched users from MySQL via PHP");

    } catch (error) {
        console.error('Error:', error);
        display.innerText = "Failed to load users via PHP";
    }
}

async function getUsersMySQLNode() {
    const display = document.getElementById('user-display-mysql');
        
    try {
        const response = await fetch('http://127.0.0.1:3000/get-users-mysql');
        
        const data = await response.json();
        display.innerText = data.map(u => u.name_).join('\n');
        console.log('Fetched users from MySQL via Node');

    } catch (error) {
        console.error('Error:', error);
    }
    
}

async function addUserMySQLNode() {
    const input = document.getElementById('user-input-mysql-node');
    const name = input.value;

    try {
        const response = await fetch('http://127.0.0.1:3000/add-user-mysql', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ user: name})
        });
        const data = await response.text();
        console.log('Node response:', data);
        input.value = '';
        getUsersMySQLNode();
    } catch (error) {
        console.error('Error:', error);
    }
}