def findscore(n, k, s):

    prefix_dic = {}

    for i in s:
        temp = 1
        while temp != k + 1:
            prefix = ''.join(i[:temp])
            if prefix in prefix_dic:
                prefix_dic[prefix] += 1
            else:
                prefix_dic[prefix] = 1
            temp += 1

    # print(prefix_dic)

    res = []
    for i in s:
        count = 0
        temp = 1
        while temp != k + 1:
            prefix = ''.join(i[:temp])
            count += prefix_dic[prefix]
            temp += 1

        res.append(count)

    return res

print(findscore(2,3,["abc","def"]))