-- 코드를 입력하세요
SELECT history_id, car_id,
date_format(start_date, '%Y-%m-%d') START_DATE,
date_format(end_date, '%Y-%m-%d') END_DATE,
if (datediff(end_date, start_date) >= 29, '장기 대여', '단기 대여') RENT_TYPE
from car_rental_company_rental_history
where year(start_date) = 2022 and month(start_date) = 9
order by history_id desc