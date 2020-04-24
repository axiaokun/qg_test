import numpy as np


# 创建不重复的词条列表
def createVocabList(dataSet):
    """
    :param dataSet: 文本中包含的所有词，list
    :return: 词集（去掉重复的词），list
    """
    vocabSet = set()
    for document in dataSet:
        vocabSet = vocabSet | set(document)  # 集合运算，集合中都包含的元素
    return list(vocabSet)


# 朴素贝叶斯词袋模型
def bagOfWords2Vec(vocabList, inputSet):
    """
    :param vocabList: 词集，list
    :param inputSet: 文本中所有词，list
    :return: 词袋模型，list
    """
    returnVec = [0] * len(vocabList)
    for word in inputSet:
        if word in vocabList: # 如果有出现这个词，那么该词数量加一
            returnVec[vocabList.index(word)] += 1

    return returnVec


class my_bayes:
    def __init__(self):
        self.p1_rate = None  # 所有样本中负类样本占的比例
        self.p0_vec_rate = None  # 每一个词在正类样本中占的比例组成的向量
        self.p1_vec_rate = None  # 每一个词在负类样本中占的比例组成的向量
        pass

    def fit(self, train_vec_matrix, train_class):
        """
        拟合训练数据
        :param train_vec_matrix: 词袋模型矩阵 ，list矩阵
        :param train_class: 样本类别 ，array
        :return:
        """
        sample_num = len(train_class)
        words_num = len(train_vec_matrix[0])
        self.p1_rate = np.sum(train_class)/sample_num
        p0_vec_sum = np.ones(words_num)  # 每一个词的数量初始化为1，也就是拉普拉斯常数λ为1，避免出现条件概率为0的情况
        p1_vec_sum = np.ones(words_num)
        p0_nums = 2  # 分母对应要增加Sλ，s取2
        p1_nums = 2

        for i in range(sample_num):
            if train_class[i]:  # 如果是负类
                p1_nums += np.sum(train_vec_matrix[i])  # 负类总词袋加上这单个向量
                p1_vec_sum += train_vec_matrix[i]  # 负类数量加1
            else:
                p0_nums += np.sum(train_vec_matrix[i])
                p0_vec_sum += train_vec_matrix[i]

        # 正类总词袋（正样本中每一个词在正类样本中出现的数量组成的向量）/ 正类数量 ， 结果取自然对数
        self.p0_vec_rate = np.log(p0_vec_sum/p0_nums)
        self.p1_vec_rate = np.log(p1_vec_sum/p1_nums)

    def predict(self, test_vec_matrix):
        """
        :param test_vec_matrix: 待预测的样本的词袋矩阵
        :return: 预测结果
        """
        class_list = []
        for i in test_vec_matrix:
            # 计算条件概率与先验概率相乘后取对数
            p1 = np.sum(i * self.p1_vec_rate) + np.log(self.p1_rate)
            p0 = np.sum(i * self.p0_vec_rate) + np.log(1 - self.p1_rate)
            if p1 > p0:
                type_i = 1
            else:
                type_i = 0
            class_list.append(type_i)
        return class_list
