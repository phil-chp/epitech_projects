const db = require('../../config/db')
const mWare = require('../../middleware/auth')
const mWareCheck = require('../../middleware/notFound')

const init_user_query = module.exports.init_user_query = function (app) {

  app.put('/user/:id', mWareCheck.token_check, mWare.id_standalone,
  mWare.user_call, mWareCheck.check_putinfo,
  mWare.update_user, (req, res) => {
    var sql = `SELECT * FROM user WHERE id=${req.params.id}`
    db.pool.query(sql, function (err, rows) {
      res.type('application/json')
      if (err)
        db.handle_errors(res);
      var resJson = rows[0]
      resJson.email = req.body.email
      resJson.created_at = req.body.created_at
      res.set('token', req.header('token'))
      res.send(JSON.stringify(resJson, null, 4));
    })
  });


  app.delete('/user/:id', mWareCheck.token_check, mWare.id_standalone, (req, res) => {
    res.type('application/json')
    var sql = `DELETE FROM user WHERE id=${req.params.id}`
    db.pool.query(sql, function (err, rows) {
      if (err)
        db.handle_errors(res);
    })
    res.set('token', req.header('token'))
    res.send(JSON.stringify({msg: `successfully deleted record number: ${req.params.id}`}, null, 4));
  });
}
