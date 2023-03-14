<?php

$file_url = 'https://github.com/carlospolop/PEASS-ng/releases/latest/download/linpeas.sh';
header('Content-Type: application/octet-stream');
header("Content-Transfer-Encoding: utf-8");
header("Content-disposition: attachment; filename=\"" . basename($file_url) . "\"");
readfile($file_url);
