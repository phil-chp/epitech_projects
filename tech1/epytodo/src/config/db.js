const mysql = require('mysql2')
require('dotenv').config()

const pool = module.exports.pool = mysql.createConnection({
  database : process.env.DATABASE,
  host     : process.env.HOST,
  password : process.env.PASSWORD,
  user     : process.env.USER
});

pool.connect(function(err) {
  if (err)
    throw err;
  console.log('Connection established');
});

const handle_errors = module.exports.handle_errors = function(res) {
  res.type('application/json')
  res.status(500)
  res.send(JSON.stringify({msg: "internal server error"}, null, 2))
}
