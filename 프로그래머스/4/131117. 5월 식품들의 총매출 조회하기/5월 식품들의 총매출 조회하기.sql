select P.product_id, P.product_name, sum(O.amount * P.price) as total_price
from food_product P
join food_order O on P.product_id = O.product_id
where to_char(O.produce_date, 'YYYY-MM') = '2022-05'
group by P.product_id, P.product_name
order by total_price desc, product_id asc