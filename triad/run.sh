make clean
make main

datas="citation_data_science citation_software email_enron email_eu metabolic_iAF1260b metabolic_iJO1366 qna_math qna_server bitcoin_2014 bitcoin_2015 bitcoin_2016"


echo "START"

for data in ${datas[@]}
do
    echo "data="${data}
    ./main ${data}
done

echo "END"
