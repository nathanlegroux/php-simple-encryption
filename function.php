<?php
function mdp($mdp, $action = 'illisible')
{

    $illisible = "AES-256-CBC";

    $clef2 = '8hgn5HJ5g27';

    $hash = hash('sha256', $clef);

    $iv = substr(hash('sha256', $clef2) , 0, 16);

    if ($action == 'illisible')
    { // Encrypter
        $reponse = openssl_encrypt($mdp, $illisible, $hash, 0, $iv);

        $reponse = base64_encode($reponse);

    }
    else if ($action == 'lisible')
    { // Decrypter
        $reponse = openssl_decrypt(base64_decode($mdp) , $illisible, $hash, 0, $iv);

    }

    return $reponse;
}

?>
