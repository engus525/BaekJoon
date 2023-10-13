select category, sum(sales)
from book B
join book_sales S on B.book_id = S.book_id
where to_char(S.sales_date, 'YYYY-MM') = '2022-01'
group by category
order by category asc