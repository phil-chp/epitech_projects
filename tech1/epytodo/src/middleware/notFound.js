const crypt = require('bcryptjs')
const jwt = require('jsonwebtoken')
const db = require('../config/db')

const token_check = module.exports.token_check = function (req, res, next) {
  res.type('application/json')
  if (req.body.token != undefined) {
    try {
      var dcode = jwt.verify(req.body.token, process.env.SECRET);
    } catch(err) {
      res.send(JSON.stringify({msg: "Token is not valid"}, null, 2))
    }
    if (dcode != undefined)
      next()
  } else {
    res.send(JSON.stringify({msg: "No token, authorization denied"}, null, 2))
  }
}

const credentials_check = module.exports.credentials_check = function (req, res, next) {
  try {
    var sql = `SELECT * FROM user WHERE email="${req.body.email}"`
  } catch (e) {
    db.handle_errors(res);
  }
  db.pool.query(sql, function (err, quered) {
    res.type('application/json')
    if (err) {
      db.handle_errors(res);
    } else if (quered.length > 0) {
      crypt.compare(req.body.password, quered[0].password).then(function(result) {
        if (result)
          next()
        else
          res.send(JSON.stringify({msg: "Invalid Credentials"}, null, 2))
      });
    } else {
      res.send(JSON.stringify({msg: "Invalid Credentials"}, null, 2))
    }
  });
}

const check_id = module.exports.check_id = function (req, res, next) {
  if (req.params.unique.match(/^[0-9]+$/i) != null) {
    try {
      var sql = `SELECT * FROM user WHERE id=${req.params.unique}`
    } catch (e) {
      db.handle_errors(res);
    }
    db.pool.query(sql, function (err, quered) {
      if (err) {
        db.handle_errors(res);
      } else if (quered.length <= 0) {
        next()
      } else {
        res.type('application/json')
        quered[0].created_at = JSON.stringify(quered[0].created_at)
        res.send(JSON.stringify(quered[0], null, 2))
      }
    });
  } else {
    next()
  }
}

const check_email = module.exports.check_email = function (req, res, next) {
  try {
    var sql = `SELECT * FROM user WHERE email="${req.params.unique}"`
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

const check_putinfo = module.exports.check_putinfo = function(req, res, next) {
  var sql = `SELECT * FROM user WHERE id=${req.params.id}`
  db.pool.query(sql, function (err, quered) {
    if (err)
      b.handle_errors(res);
    var row = quered[0];
    if (row.password != req.body.password
    || req.body.created_at != utils.correctDate(JSON.stringify(row.created_at))
    || row.firstname != req.body.firstname || row.name != req.body.name) {
      db.handle_errors(res);
    } else {
      next();
    }
  });
}

const check_todo = module.exports.check_todo = function (req, res, next) {
  if (req.body.title    == undefined || req.body.description == undefined
  ||  req.body.due_time == undefined || req.body.user_id     == undefined
  ||  req.body.status   == undefined) {
    db.handle_errors(res)
  } else {
    if (req.body.user_id.match(/^[0-9]+$/i) != null
    && (req.body.status == 'not started' || req.body.status == 'done'
    || req.body.status  == 'todo'        || req.body.status == 'in progress')) {
      next()
    } else {
      db.handle_errors(res);
    }
  }
}

const not_exist = module.exports.not_exist = function (req, res, next) {
  try {
    var sql = `SELECT * FROM user WHERE email='${req.body.email}'`
  } catch (e) {
    db.handle_errors(res);
  }
  db.pool.query(sql, function (err, result) {
    if (err) {
      throw err;
    } else if (result.length > 0) {
      res.type('application/json')
      res.send(JSON.stringify({msg : "account already exists"}, null, 2))
    } else {
      next()
    }
  });
}
