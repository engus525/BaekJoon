select RI.rest_id, rest_name, food_type, favorites, address
, round(avg(review_score),2) as score
from rest_info RI
join rest_review RR on RI.rest_id = RR.rest_id
where address like '서울%'
group by RI.rest_id
order by score desc, favorites desc
