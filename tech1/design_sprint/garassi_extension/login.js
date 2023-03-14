document.addEventListener('DOMContentLoaded', function() {

  document.getElementById("login_send").addEventListener('click', function() {
    var l_form = {
      username: document.getElementById("login_username").value,
      password: document.getElementById("login_password").value
    }

    if (l_form.username.length < 4
    ||  l_form.password.length < 4) {
      document.getElementById("err_warn").style.animation = "warning 1.2s linear infinite";
      document.getElementById("err_warn").innerHTML = "! Please fill in the form !";
    } else {
      document.getElementById("err_warn").style.animation = "success 1s linear infinite";
      document.getElementById("err_warn").innerHTML = "Logging in...";
      // handle login
      window.location.href = "index.html";
    }
  });

  document.getElementById("register_send").addEventListener('click', function() {
    var r_form = {
      username: document.getElementById("register_username").value,
      password: document.getElementById("register_password").value,
      cpassword: document.getElementById("f_cpassword").value
    }

    if (r_form.username.length < 4
    ||  r_form.password.length < 4
    ||  r_form.password !== r_form.cpassword) {
      document.getElementById("err_warn").style.animation = "warning 1.2s linear infinite";
      document.getElementById("err_warn").innerHTML = "! Please fill in the form !";
    } else {
      document.getElementById("err_warn").style.animation = "success 1s linear infinite";
      document.getElementById("err_warn").innerHTML = "Registering...";
      // handle register
      window.location.href = "index.html";
    }
  });
});
