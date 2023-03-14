const crypt = require('bcryptjs')
const db = require('../config/db')

const form_register = module.exports.form_register = function (req, res, next) {
  if (req.body.email == undefined || req.body.password == undefined
  || req.body.name == undefined || req.body.firstname == undefined) {
    res.type('application/json')
    res.send(JSON.stringify({msg : "internal server error"}, null, 2))
  } else {
    next()
  }
}

const register_middleware = module.exports.register_middleware = function (req, res, next) {
  try {
    crypt.hash(req.body.password, 10).then(function(hash) {
      var sql =  `INSERT INTO user (email, password, name, firstname)
                  VALUES ('${req.body.email}', '${hash}',
                  '${req.body.name}', '${req.body.firstname}')`
      db.pool.query(sql, function (err, result) {
        if (err)
          db.handle_errors(res);
      })
    });
  } catch (err) {
    db.handle_errors(res);
  }
  next()
}

const id_standalone = module.exports.id_standalone = function (req, res, next) {
  try {
    if (req.params.id.match(/^[0-9]+$/i) != null)
      var sql = `SELECT * FROM todo WHERE id=${req.params.id}`
    else
      db.handle_errors(res)
  } catch (e) {
    db.handle_errors(res);
  }
  db.pool.query(sql, function (err, quered) {
    if (err) {
      db.handle_errors(res);
    } else if (quered.length > 0) {
      next()
    } else {
      res.type('application/json')
      res.status(404)
      res.send(JSON.stringify({msg: "Not Found"}, null, 2))
    }
  });
}

const login_to_form = module.exports.login_to_form = function (req, res, next) {
  if (req.body.email == undefined || req.body.password == undefined)
    db.handle_errors(res)
  else
    next()
}

const update_todo = module.exports.update_todo = function (req, res, next) {
  var sql =  `UPDATE todo SET title = '${req.body.title}',
              description = '${req.body.description}',
              due_time = CAST ('${req.body.due_time}' AS DATETIME),
              status = '${req.body.status}',
              user_id = ${req.body.user_id} WHERE id=${req.params.id}`
  db.pool.query(sql, function (err) {
    if (err)
      console.log(err); db.handle_errors(res);
  });
  next()
}

const update_user = module.exports.update_user = function (req, res, next) {
  var sql = `UPDATE user SET email = '${req.body.email}' WHERE id=${req.params.id}`
  db.pool.query(sql, function (err, result) {
    if (err)
      db.handle_errors(res);
  });
  next()
}

const user_call = module.exports.user_call = function(req, res, next) {
  if (req.body.email      == undefined || req.body.password  == undefined
  ||  req.body.name       == undefined || req.body.firstname == undefined
  ||  req.body.created_at == undefined) {
    db
    xt();
  }
}
