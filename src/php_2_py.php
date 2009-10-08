<?php
include("ZhConversion.php");

echo "# -*- coding: utf-8 -*- \n";

function printDict($name, $dict) {
    echo "$name = {\n";
    foreach($dict as $key => $val) {
        echo "    u\"", $key, "\": u\"", $val, "\",\n";
    }
    echo "}\n";
    echo "\n";
}

printDict("zh2Hant", $zh2Hant);
printDict("zh2Hans", $zh2Hans);
printDict("zh2TW", $zh2TW);
printDict("zh2HK", $zh2HK);
printDict("zh2CN", $zh2CN);
printDict("zh2SG", $zh2SG);
?>
