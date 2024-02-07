select 
B.title,
B.board_id,
R.reply_id,
R.writer_id,
R.contents,
date_format(R.created_date, '%Y-%m-%d') as CREATED_DATE
from used_goods_board B
join used_goods_reply R on B.board_id = R.board_id
where year(B.created_date) = 2022 and month(B.created_date) = 10
order by R.created_date asc, title asc