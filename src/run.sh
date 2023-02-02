make clean
make main

datas="citation_data_science citation_software email_enron email_eu metabolic_iAF1260b metabolic_iJO1366 qna_math qna_server bitcoin_2014 bitcoin_2015 bitcoin_2016"

versions="CODAE CODAA A2A Uniform" 
fs="10"
try=3

for version in ${versions[@]}
do
    echo ${version}
    for data in ${datas[@]}
    do
        echo "data="${data}
        if [ ${version} = "CODAE" ] ; then
            ./main 0 ${data} CODAE 1
        else
            for f in ${fs[@]}
            do
                echo "  fs="${f}
                ./main ${f} ${data} ${version} ${try}
            done
        fi
    done
done


#citation_data_science  V:  46646  E:  38144
#citation_software  V:  94886  E:  115617
#email_enron  V:  110  E:  1447
#email_eu  V:  986  E:  34485
#metabolic_iaf1260b  V:  1668  E:  2064
#metabolic_ijo1366  V:  1805  E:  2233
#qna_math  V:  34635  E:  83425
#qna_server  V:  163508  E:  238838
#bitcoin_2014  V:  1697625  E:  1164119
#bitcoin_2015  V:  1961886  E:  1237599
#bitcoin_2016  V:  2009978  E:  1293604