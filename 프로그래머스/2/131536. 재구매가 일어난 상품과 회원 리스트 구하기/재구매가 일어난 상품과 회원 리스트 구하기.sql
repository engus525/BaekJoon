select user_id, product_id#, count(*)
from online_sale OS
where 2 <= 
    (
        select count(*) 
        from online_sale IOS
        where OS.user_id = IOS.user_id
    )
group by product_id, user_id
having count(*) > 1
order by user_id, product_id desc
# order by product_id, user_id