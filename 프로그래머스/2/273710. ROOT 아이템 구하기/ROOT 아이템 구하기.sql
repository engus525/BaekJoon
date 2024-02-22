-- 코드를 작성해주세요
select II.item_id, II.item_name
from item_info II
join item_tree IT on II.item_id = IT.item_id
where IT.parent_item_id is null