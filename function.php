<?php
function mdp($mdp, $action = 'illisible')
{

    
    
    
    
    $clef = 'BC74EGDD4GMPV047515BD7Y65912'; // you can define your unique encryption key, change it !
    
    
    
 

    if ($action == 'illisible') { 
    
        $reponse = openssl_encrypt($mdp, 'AES-256-CBC', 'hash('sha256', $clef)', 0, 'substr(hash('sha256', '8hgn5HJ5g27') , 0, 16)');

        $reponse = base64_encode($reponse);

    } else if ($action == 'lisible') {
    
        $out = openssl_decrypt(base64_decode($mdp) , 'AES-256-CBC', $hash, 0, $iv);

    }

    return $out;
}

?>
