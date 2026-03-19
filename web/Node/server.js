const express = require('express');
const fs = require('fs');
const path = require('path');
const mysql = require('mysql2');
const cors = require('cors');
const app = express();
const port = 3000;

app.use(cors());
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.static('public'));

const webRoot = 'D:/learn/web';

const usersFile = path.join(webRoot, 'users.txt');

const db = mysql.createConnection({
    host: '127.0.0.1',
    user: 'root',      
    password: '',
    database: 'learnweb'
});


app.post('/add-user-node', (req, res) => {
    const username = req.body.user;
     
    console.log(username);

    if (username) {
        fs.appendFile(usersFile, username + '\n', (err) => {
            res.send("New user added");
        });
    } else {
        res.status(400).send("No user provided");
    } 
});


app.get('/get-users-mysql-node', (req, res) => {
    const query = "SELECT name FROM users";
    db.query(query, (err, results) => {
        if (err) 
            return res.status(500).send(err);
        res.json(results);
    });
});

app.post('/add-user-mysql-node', (req, res) => {
    const username = req.body.user;
    if (username) {
        db.query("INSERT INTO users (name) VALUES (?)", [username], (err) => {
            if (err) return res.status(500).send(err);
            res.send("User added to MySQL");
        });
    } else {
        res.status(400).send("Empty username");
    }
});


app.post('/create-hacker', (req, res) => {
    const name = req.body.name;
    const dirPath = path.join(webRoot, name);

    if (!name)
        return res.status(400).send("Name is required");

    const sql = "INSERT INTO hackers (name) VALUES (?)";
    db.query(sql, [name], (err, result) => {
        if (err)
            return res.status(500).send("Database error: " + err.message);

        fs.mkdir(dirPath, { recursive: true }, (err) => {
            if (err)
                return res.status(500).send("Error creating hacker");
            
            const filePath = path.join(dirPath, 'index.html');
            const content = `<h1> Hacker ${name} created via Node </h1>`;
            
            fs.writeFile(filePath, content, (err) => {
                if (err)
                    return res.status(500).send("Error creating file");
                res.send(`Created /${name}/index.html`);
            });
        });
    });
});

app.get('/get-hackers', (req, res) => {
    const query = "SELECT name FROM hackers ORDER BY id DESC";
    
    db.query(query, (err, results) => {
        if (err) 
            return res.status(500).send("Database error: + " + err.message);
        res.json(results);
    });
});


app.listen(port, () => {
    console.log(`Node server running at http://127.0.0.1:${port}`);
});