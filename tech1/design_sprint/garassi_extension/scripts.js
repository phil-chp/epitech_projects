var errno = undefined;
var stars = []
var query = {
  grade: -1,
  comment: undefined,
  url: undefined,
  title: undefined,
  userID: 0
}

function fillQuery() {
  errno = undefined;
  if (query.grade == -1) {
    errno = "! WARNING: You need to set a grade. !";
  }
  if (query.url == undefined || query.title == undefined) {
    errno = "! ERROR: Webpage not found. !";
  }
  if ((query.comment = document.getElementById("text").value.length) < 4) {
    errno = "! WARNING: you need to set a comment. !";
  }
  if (query.userID == undefined) {
    errno = "! ERROR: You need to log in. !";
  }
  return ((errno == undefined ? 0 : 1));
}

document.addEventListener('DOMContentLoaded', function() {
  stars = [
    document.getElementById("star1"),
    document.getElementById("star2"),
    document.getElementById("star3"),
    document.getElementById("star4"),
    document.getElementById("star5")
  ]

  for (let i = 0; i < stars.length; i++) {
    stars[i].addEventListener('click', function() {
      query.grade = i;
      setGrade(i);
    });
  }

  document.getElementById("send").addEventListener('click', function() {
    if (fillQuery()) {
      document.getElementById("err_warn").style.animation = "warning 1.2s linear infinite";
      document.getElementById("err_warn").innerHTML = errno;
    } else {
      document.getElementById("err_warn").style.animation = "success 1s linear infinite";
      document.getElementById("err_warn").innerHTML = "Comment successfully posted.";
      sendQuery();
    }
  });
});

function sendQuery() {
  var xhr = new XMLHttpRequest();

  xhr.open("POST", 'https://www.ghizzo.fr', true);
  xhr.setRequestHeader('Content-Type', 'application/json');
  xhr.send(JSON.stringify({
    value: value
  }));
}

function setGrade(i) {
  var star_empty = "assets/textures/star_empty.png";
  var star_fill = "assets/textures/star_fill.png";

  for (let n = 0; n < 5; n++) {
    if (n <= i) {
      stars[n].src = star_fill;
    } else {
      stars[n].src = star_empty;
    }
  }
  return (0);
}

chrome.tabs.getSelected(null, function(tab) {
  var title = tab.title;
  var name = new URL(tab.url.toString());

  document.getElementById("web_url").innerHTML = name;
  query.url = name;

  document.getElementById("web_title").innerHTML = title;
  query.title = title;
});
