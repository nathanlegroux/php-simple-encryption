<?php
function mdp($mdp, $action = 'illisible')
{
  

    $k2 = substr(hash('sha256', '8hgn5HJ5g27') , 0, 16);
    $hash = hash('sha256', $clef);

    if ($action == 'illisible')
    { 
        $reponse = openssl_encrypt($mdp, 'AES-256-CBC', $hash, 0, $k2);

        $reponse = base64_encode($reponse);

    }

    if ($action == 'lisible')
    { 
        $reponse = openssl_decrypt(base64_decode($mdp) , 'AES-256-CBC', $hash, 0, $k2);

    }

    return $reponse;
}

?>
