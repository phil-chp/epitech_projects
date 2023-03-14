const jwt = require('jsonwebtoken')
const mWare = require('../../middleware/auth')
const mWareCheck = require('../../middleware/notFound')

const init_register = module.exports.init_register = function (app) {
  app.post('/register', mWare.form_register, mWareCheck.not_exist, mWare.register_middleware, (req, res) => {
    res.type('application/json')
    var token = jwt.sign(req.body.email, process.env.SECRET)
    res.set('token', token)
    res.send(JSON.stringify({token: token}, null, 2));
  })
}

const init_login = module.exports.init_login = function (app) {
  app.post('/login', mWare.login_to_form, mWareCheck.credentials_check, (req, res) => {
    res.type('application/json')
    var token = jwt.sign(req.body.email, process.env.SECRET)
    res.set('token', token)
    res.send(JSON.stringify({token: token}, null, 2));
  })
}
