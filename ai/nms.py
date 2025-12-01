import numpy as np
 
# 大量 candidate -[topK]-> K 个候选 -[NMS]-> 最终结果
def IOU(bbox, bboxes):
    #x1,y1,x2,y2
    area_1 = (bbox[2]-bbox[0])* (bbox[3]-bbox[1])
    area_n = (bboxes[:, 2]-bboxes[:,0])* (bboxes[:, 3]-bboxes[:,1])
 
    x_1 = np.maximum(bbox[0], bboxes[:,0])
    x_2 = np.minimum(bbox[2], bboxes[:,2])
     
    y_1 = np.maximum(bbox[1], bboxes[:,1])
    y_2 = np.minimum(bbox[3], bboxes[:,3])
     
    inter_area = np.maximum(x_2-x_1, 0)*np.maximum(y_2-y_1, 0)
     
    iou = inter_area/(area_1+area_n-inter_area)
    return iou
     
 
def NMS(preds, thresh):
    """
    :preds: np.array
    :thresh: float
    """
     
    bboxes, score = preds[:,:4], preds[:,4]
    index = np.argsort(score)[::-1]
    res = []
    while len(index)>0:
        res.append(index[0])
        cur_bbox= bboxes[index[0]]
        iou = IOU(cur_bbox, bboxes[index[1:]])
        keep_idx = np.where(iou<thresh)[0]
        # index = index[keep_idx+1]
        index = index[1:][keep_idx] # 效果等价
    return res  
     
 
if __name__ == "__main__":
    preds = np.array([
        [10, 20, 30, 40, 0.8],
        [12, 22, 32, 45, 0.33],
        [16, 28, 38, 49, 0.6],
        [15, 28, 39, 50, 0.7]
    ])
    thresh = 0.5
    result = NMS(preds=preds, thresh=thresh)
    print(result)