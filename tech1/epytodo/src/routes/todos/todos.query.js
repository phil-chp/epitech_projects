const db = require('../../config/db')
const mWare = require('../../middleware/auth')
const mWareCheck = require('../../middleware/notFound')

const init_todo_query = module.exports.init_todo_query = function (app) {

  app.put('/todo/:id', mWareCheck.token_check, mWare.id_standalone, mWareCheck.check_todo, mWare.update_todo, function (req, res) {
    res.type('application/json')
    res.set('token', req.header('token'))
    res.send(JSON.stringify({...req.body}, null, 4))
  });


  app.delete('/todo/:id', mWareCheck.token_check, mWare.id_standalone, function (req, res) {
    var sql = `DELETE FROM todo WHERE id=${req.params.id}`
    res.type('application/json')
    db.pool.query(sql, function (err, result) {
      if (err)
        db.handle_errors(res)
    })
    res.set('token', req.header('token'))
    res.send(JSON.stringify({msg: `successfully deleted record number: ${req.params.id}`}, null, 4));
  });
}
